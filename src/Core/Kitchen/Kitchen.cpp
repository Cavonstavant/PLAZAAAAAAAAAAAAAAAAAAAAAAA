/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Kitchen
*/

/// \file src/Core/Kitchen/Kitchen.cpp

#include "Kitchen.hpp"
#include "Cook.hpp"
#include "Pizza.hpp"
#include <ctime>
#include <functional>

using namespace plazza;

void Kitchen::start()
{
    _oldTime = std::time(nullptr);
    _initFridge(this);
    _brigade.emplace_back(std::thread(_timerCook, this));
    for (std::size_t i = 0; i < _nbCooks; ++i)
        _brigade.emplace_back(std::thread(_Cook, this));
}

void Kitchen::getIngredientsFromPizzaType(Pizza &toCook, PizzaType type)
{
    Ingredient ingredient;

    switch (type) {
    case Margarita:
        ingredient.name = "doe";
        ingredient.number = 1;
        toCook.ingredients.push_back(ingredient);
        ingredient.name = "tomato";
        ingredient.number = 1;
        toCook.ingredients.push_back(ingredient);
        ingredient.name = "gruyere";
        ingredient.number = 1;
        toCook.ingredients.push_back(ingredient);
        break;
    case Regina:
        ingredient.name = "doe";
        ingredient.number = 1;
        toCook.ingredients.push_back(ingredient);
        ingredient.name = "tomato";
        ingredient.number = 1;
        toCook.ingredients.push_back(ingredient);
        ingredient.name = "gruyere";
        ingredient.number = 1;
        toCook.ingredients.push_back(ingredient);
        ingredient.name = "ham";
        ingredient.number = 1;
        toCook.ingredients.push_back(ingredient);
        ingredient.name = "mushrooms";
        ingredient.number = 1;
        toCook.ingredients.push_back(ingredient);
        break;
    case Americana:
        ingredient.name = "doe";
        ingredient.number = 1;
        toCook.ingredients.push_back(ingredient);
        ingredient.name = "tomato";
        ingredient.number = 1;
        toCook.ingredients.push_back(ingredient);
        ingredient.name = "gruyere";
        ingredient.number = 1;
        toCook.ingredients.push_back(ingredient);
        ingredient.name = "steak";
        ingredient.number = 1;
        toCook.ingredients.push_back(ingredient);
        break;
    case Fantasia:
        ingredient.name = "doe";
        ingredient.number = 1;
        toCook.ingredients.push_back(ingredient);
        ingredient.name = "tomato";
        ingredient.number = 1;
        toCook.ingredients.push_back(ingredient);
        ingredient.name = "eggplant";
        ingredient.number = 1;
        toCook.ingredients.push_back(ingredient);
        ingredient.name = "goatCheese";
        ingredient.number = 1;
        toCook.ingredients.push_back(ingredient);
        break;
    }
}

bool Kitchen::_isAvailableCook(std::string &command)
{
    if (command == "avail_slots?")
        return (true);
    return (false);
}

void Kitchen::_timerCook(Kitchen *obj)
{
    bool isWorking = false;
    time_t timer = std::time(nullptr);

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        {
            std::unique_lock<std::mutex> lock(obj->_mutex);
            if (!isWorking && (obj->_availCooks < obj->_nbCooks || !obj->_orders.empty())) {
                isWorking = true;
            }
            if (isWorking && obj->_availCooks == obj->_nbCooks && obj->_orders.empty()) {
                timer = std::time(nullptr);
                isWorking = false;
            }
            if (isWorking == false && std::time(nullptr) - timer >= 5) {
                obj->_needToBeKilled = true;
                return;
            }
        }
    }
}

void Kitchen::work()
{
    _receptCook(this);
}

void Kitchen::_receptCook(Kitchen *obj)
{
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::string fullCommand = obj->commandQueue.get()->receiveMessage();

        if (fullCommand.find("avail_slots:") == 0) {
            obj->commandQueue.get()->sendMessage(fullCommand);
            continue;
        }
        if (_isAvailableCook(fullCommand)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            std::string message = "avail_slots:" + std::to_string(obj->_orders.size() + (obj->_nbCooks - obj->_availCooks)) + ";fridge:";
            {
                std::unique_lock<std::mutex> lock(obj->_fridgeMutex);
                for (size_t x = 1; x < IngredientNumber; x++) {
                    message.append(obj->_fridge[x].name);
                    message.append("," + std::to_string(obj->_fridge[x].number) + ";");
                }
            }
            obj->commandQueue.get()->sendMessage(message);
            continue;
        }
        if (fullCommand.find("exit") == 0) {
            if (fullCommand.find("exit:") == 0) {
                obj->commandQueue.get()->sendMessage(fullCommand);
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                continue;
            }
            if (obj->_needToBeKilled == true) {
                obj->commandQueue.get()->sendMessage("exit:OK");
                obj->stop();
                return;
            } else {
                obj->commandQueue.get()->sendMessage("exit:KO");
            }
            continue;
        }
        Pizza toCook = unpack(fullCommand);
        obj->enqueueJob(toCook);
        // size_t quantity = toCook.number;
        // toCook.number = 1;
        // getIngredientsFromPizzaType(toCook, toCook.type);

        // for (std::size_t x = 0; x < quantity; ++x) {
        //     obj->enqueueJob(toCook);
        // }
    }
}

Pizza Kitchen::unpack(const std::string &order)
{
    Pizza pizza;
    std::string tmp = order;

    tmp = tmp.substr(tmp.find("name:") + 5);
    pizza.type = PizzaType(std::atoi(tmp.c_str()));
    tmp = tmp.substr(tmp.find(";size:") + 6);
    pizza.size = PizzaSize(std::atoi(tmp.c_str()));
    tmp = tmp.substr(tmp.find(";amount:") + 8);
    pizza.number = std::atoi(tmp.c_str());
    return (pizza);
}

void Kitchen::_Cook(Kitchen *obj)
{
    Cook cook;
    bool asEnoughIngredients = false;
    cook.setCookingTimeMultipiler(obj->_cookingTime);

    while (true) {
        Pizza order;
        {
            std::unique_lock<std::mutex> lock(obj->_mutex);
            obj->order_condition.wait(lock, [&obj] {
                return !obj->_orders.empty() || obj->_stopKitchen;
            });
            if (obj->_stopKitchen) {
                return;
            }
            order = obj->_orders.front();
            obj->_orders.pop();
            obj->_availCooks--;
        }
        {
            std::unique_lock<std::mutex> lock(obj->_fridgeMutex);
            while (!asEnoughIngredients) {
                _waitToFillFridge(obj->_refillTime, obj);
                try {
                    obj->_fridge -= order;
                } catch (...) {
                    continue;
                }
                asEnoughIngredients = true;
            }
        }
        cook.cookPizza(order);
        {
            std::unique_lock<std::mutex> lock(obj->_mutex);
            obj->_availCooks++;
        }
    }
}

void Kitchen::enqueueJob(Pizza &pizza)
{
    bool notify = false;
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _orders.emplace(pizza);
    }
    while (!notify) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        {
            std::unique_lock<std::mutex> lock(_mutex);
            notify = (_availCooks) ? true : false;
        }
    }
    order_condition.notify_one();
}

bool Kitchen::isBusy()
{
    bool busy;
    {
        std::unique_lock<std::mutex> lock(_mutex);
        busy = _orders.empty();
    }
    return busy;
}

void Kitchen::stop()
{
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _stopKitchen = true;
    }
    order_condition.notify_all();
    std::size_t index = 0;
    for (std::thread &active_thread: _brigade) {
        active_thread.join();
        index++;
    }
    _brigade.clear();
}

void Kitchen::_fillFridge(const std::size_t &timeToFill, Kitchen *obj)
{
    for (auto &ingredient: obj->_fridge) {
        ingredient.number += timeToFill;
    }
}

void Kitchen::_waitToFillFridge(const std::size_t &timeToWait, Kitchen *obj)
{
    if (std::time(nullptr) - obj->_oldTime > timeToWait) {
        obj->_oldTime = std::time(nullptr);
        _fillFridge(1, obj);
    }
}

void Kitchen::_initFridge(Kitchen *obj)
{
    obj->_fridge[Tomato].name = "tomato";
    obj->_fridge[Gruyere].name = "gruyere";
    obj->_fridge[Ham].name = "ham";
    obj->_fridge[Mushrooms].name = "mushrooms";
    obj->_fridge[Steak].name = "steak";
    obj->_fridge[Eggplant].name = "eggplant";
    obj->_fridge[GoatCheese].name = "goatCheese";
    obj->_fridge[Doe].name = "doe";
    _fillFridge(5, obj);
}
