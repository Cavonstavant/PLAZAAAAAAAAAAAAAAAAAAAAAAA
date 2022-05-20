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
    _initFridge(*this);
    _brigade.emplace_back(std::thread(_receptCook, this));
    for (std::size_t i = 0; i < _nbCooks; ++i)
        _brigade.emplace_back(std::thread(_Cook, this));
}

PizzaType Kitchen::getTypeFromFullCommand(const std::string &fullCommand)
{
    std::string name = fullCommand.substr(0, fullCommand.find(";"));

    name = name.substr(name.find(":") + 1);
    switch (stoi(name)) {
        case Regina:
            return Regina;
        case Margarita:
            return Margarita;
        case Americana:
            return Americana;
        case Fantasia:
            return Fantasia;
        default:
            throw VeryStupidUserEX("Not supposed to happen (PizzaType)", Logger::CRITICAL);
    }
}

int Kitchen::getQuantityFromFullCommand(const std::string &fullCommand)
{
    std::string quantity = fullCommand.substr(fullCommand.find(";") + 1);

    quantity = quantity.substr(quantity.find(";") + 1);
    quantity = quantity.substr(quantity.find(":") + 1);
    return stoi(quantity);
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
            ingredient.name = "chiefLove";
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

void Kitchen::_receptCook(Kitchen *obj)
{
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::string fullCommand = obj->commandQueue.get()->receiveMessage();

        if (_isAvailableCook(fullCommand)) {
            obj->commandQueue.get()->sendMessage("avail_slots:" + std::to_string(obj->_availCooks));
            continue;
        }
        Pizza toCook = unpack(fullCommand);
        getIngredientsFromPizzaType(toCook, toCook.type);

        for (std::size_t x = 0; x < toCook.number; ++x)
            obj->_orders.push(toCook);
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
    cook.setCookingTimeMultipiler(obj->_cookingTime);

    obj->_availCooks = obj->_nbCooks;
    while (true) {
        Pizza order;
        {
            std::unique_lock<std::mutex> lock(obj->_mutex);
            obj->order_condition.wait(lock, [&obj] {
                return !obj->_orders.empty() || obj->_stopKitchen;
            });
            if (obj->_stopKitchen)
                return;
            order = obj->_orders.front();
            obj->_orders.pop();
            obj->_availCooks--;
        }
        _waitToFillFridge(obj->_refillTime, *obj);
        cook.cookPizza(order);
        {
            std::unique_lock<std::mutex> lock(obj->_mutex);
            obj->_availCooks++;
        }
    }
}

void Kitchen::enqueueJob(Pizza &pizza)
{
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _orders.emplace(pizza);
    }
    order_condition.notify_one();
}

void Kitchen::stop()
{
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _stopKitchen = true;
    }
    order_condition.notify_all();
    for (std::thread &active_thread: _brigade) {
        active_thread.join();
    }
    _brigade.clear();
}

void Kitchen::_fillFridge(const std::size_t &timeToFill, Kitchen &obj)
{
    for (std::size_t x = 0; x < IngredientNumber; ++x) {
        obj._fridge[x].number += timeToFill;
    }
}

void Kitchen::_waitToFillFridge(const std::size_t &timeToWait, Kitchen &obj)
{
    if (std::time(nullptr) - obj._oldTime > timeToWait) {
        obj._oldTime = std::time(nullptr);
        _fillFridge(1, obj);
    }
}

void Kitchen::_initFridge(Kitchen &obj)
{
    obj._fridge[Tomato].name = "tomato";
    obj._fridge[Gruyere].name = "gruyere";
    obj._fridge[Ham].name = "ham";
    obj._fridge[Mushrooms].name = "mushrooms";
    obj._fridge[Steak].name = "steak";
    obj._fridge[Eggplant].name = "eggplant";
    obj._fridge[GoatCheese].name = "goatCheese";
    obj._fridge[ChiefLove].name = "chiefLove";
    obj._fridge[Doe].name = "doe";
    _fillFridge(5, obj);
}
