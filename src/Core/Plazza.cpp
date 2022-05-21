/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAA
** File description:
** Plazza
*/

/// \file src/Core/Plazza.cpp

#include "Plazza.hpp"
#include "Exception.hpp"
#include "Kitchen/Kitchen.hpp"
#include <iostream>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <utility>

using namespace plazza;

Reception::Reception(float cookingTime, size_t cookNumber, size_t refillTime)
{
    _cookingTime = cookingTime;
    _cookNumber = cookNumber;
    _refillTime = refillTime;
    _availSlotsTotal = 0;
}

void Reception::_displayKitchensStatus(void)
{
    std::cout << "Status command not implemented yet." << std::endl;
}

bool Reception::_handleInput(const std::string &input)
{
    InputParser server;

    server.setCommand(input);
    try {
        server.processArguments();
    } catch (const PlazzaException &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    _manageOrders(server);
    return true;
}

bool Reception::_isNewKitchenNeeded(int pizzaAmt)
{
    if (_availSlotsTotal < pizzaAmt)
        return true;
    return false;
}

void Reception::_updateBusyCooks(void)
{
    std::string kitchenResponse;
    unsigned int tmp_avail = 0;

    for (auto &kitchen : _kitchenMap) {
        kitchen.second->sendMessage("avail_slots?");
        kitchenResponse = kitchen.second->receiveMessage();
        while (kitchenResponse.find("avail_slots:") == std::string::npos) {
            kitchen.second->sendMessage("avail_slots?");
            kitchenResponse = kitchen.second->receiveMessage();
        }
        {
            kitchen.second->sendMessage(kitchenResponse);
            kitchenResponse = kitchen.second->receiveMessage();
        }
        try {
            tmp_avail = std::stoi(kitchenResponse.substr(kitchenResponse.find(":") + 1));
        } catch (const std::exception &e) {
            std::cerr << "Error: " << kitchenResponse << " " << e.what() << std::endl;
            return;
        }
        _availSlots[kitchen.first] = _cookNumber - tmp_avail;
        _availSlotsTotal += _cookNumber - tmp_avail;
    }
}

void Reception::_createNewKitchen(void)
{
    Kitchen newKitchen(_cookNumber, _refillTime, _cookingTime);
    std::shared_ptr<MessageQueue> newQueue = std::make_shared<MessageQueue>();
    pid_t newKitchenPid;

    newQueue.get()->openQueue(std::string("/plazzaQueueNumber" + std::to_string(_kitchenMap.size())));
    newKitchenPid = fork();
    if (newKitchenPid == 0) {
        newKitchen.commandQueue = newQueue;
        newKitchen.start();
        // newKitchen.stop();
    } else
        _kitchenMap[newKitchenPid] = newQueue;
}

void Reception::_sendPizza(std::vector<Pizza> &pizzaToCook, int amt, pid_t kitchenPid)
{
    Pizza tmpPizza = pizzaToCook.back();
    for (int x = 0; x < amt; ++x) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        _kitchenMap[kitchenPid]->sendMessage(pack(tmpPizza));
        pizzaToCook.pop_back();
        tmpPizza = pizzaToCook.back();
    }
}

void Reception::_manageOrders(const InputParser &command)
{
    std::vector<Pizza> pizzaToCook = command.getPizza();
    unsigned int pizzaPerKitchen = 0;

    if (pizzaToCook.size() == 0)
        return;
    _updateBusyCooks();
    if (!_kitchenMap.empty())
        pizzaPerKitchen = _availSlotsTotal + pizzaToCook.size() / _kitchenMap.size();
    if (_kitchenMap.empty() || _isNewKitchenNeeded(pizzaToCook.size())){
        if (_kitchenMap.size() < 9){
            _createNewKitchen();
            _updateBusyCooks();
        } else
            std::cout << "Could not open more than 9 Kitchens without running the program as root:"
                << "\n\tWaiting for previous orders to finish..." << std::endl;
    }
    while (!pizzaToCook.empty()) {
        for (auto &kitchen : _kitchenMap) {
            if (_availSlots[kitchen.first] < (_cookNumber * 2))
                _sendPizza(pizzaToCook, pizzaPerKitchen, kitchen.first);
            if (pizzaToCook.empty())
                break;
        }
    }
}

std::string Reception::pack(const Pizza &pizza)
{
    std::string order = "";

    order.append("name:");
    order.append(std::to_string(pizza.type));
    order.append(";size:");
    order.append(std::to_string(pizza.size));
    order.append(";amount:");
    order.append(std::to_string(pizza.number));
    order.append("\n");
    return (order);
}

Pizza Reception::unpack(const std::string &order)
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

void Reception::_cleanKitchens(void)
{
    for (auto x = _kitchenMap.begin(); x != _kitchenMap.end(); ++x) {
        kill(x->first, SIGTERM);
    }
}

void Reception::run()
{
    std::string input;

    while (true) {
        if (!std::getline(std::cin, input))
            return;

        if (input == "exit") {
            break;
        } else if (input == "status") {
            _displayKitchensStatus();
        } else if (input == "clear" || input == "c") {
            std::system("clear");
        } else {
            if (!_handleInput(input)) {
                ParserEX(input + " has a invalid pizza command.", Logger::INFO);
            }
        }
    }
    _cleanKitchens();
}
