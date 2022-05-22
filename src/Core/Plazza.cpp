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
#include <tuple>
#include <unistd.h>
#include <utility>

using namespace plazza;
using namespace std::string_literals;

Reception::Reception(float cookingTime, size_t cookNumber, size_t refillTime)
{
    _cookingTime = cookingTime;
    _cookNumber = cookNumber;
    _refillTime = refillTime;
    _endRun = false;
    _availSlotsTotal = 0;
}

int Reception::_isAvailableSlots(std::string message)
{
    int slots = 0;

    if (message.find("avail_slots:") == 0) {
        message = message.substr(message.find(":") + 1);
        try {
            slots = std::stoi(message);
        } catch (std::exception &e) {
            PlazzaEX(message + ": "s + e.what(), Logger::INFO);
            return (-1);
        }
    } else
        return (-1);
    return (slots);
}

void Reception::_displayKitchensStatus(void)
{
    pid_t pid;
    int cookAvailable = 0;
    std::string message;

    {
        std::unique_lock<std::mutex> lock(_mutex);
        std::cout << "Available Kitchen: " << _kitchenMap.size() << std::endl;
    }
    for (auto it: _kitchenMap) {
        {
            std::unique_lock<std::mutex> lock(_mutex);
            std::cout << "====================" << std::endl;
            pid = it.first;
            std::cout << "Kitchen PID: " << (int) pid << std::endl;
            it.second.get()->sendMessage("avail_slots?");
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            message = it.second.get()->receiveMessage();
            while (_isAvailableSlots(message) < 0) {
                it.second.get()->sendMessage(message);
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                message = it.second.get()->receiveMessage();
            }
            cookAvailable = _isAvailableSlots(message);
            std::cout << "Available slots: " << _cookNumber * 2 - cookAvailable << "/" << _cookNumber * 2 << std::endl;
            std::cout << "Fridge:" << std::endl;
            message = message.substr(message.find("fridge"));
            message = message.substr(message.find(":") + 1);
            while (!message.empty()) {
                std::cout << message.substr(0, message.find(","));
                message = message.substr(message.find(",") + 1);
                std::cout << ": " << message.substr(0, message.find(";")) << std::endl;
                message = message.substr(message.find(";") + 1);
            }
            std::cout << "====================" << std::endl;
        }
    }
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

bool Reception::_isNewKitchenNeeded(unsigned int pizzaAmt)
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
            kitchen.second->sendMessage(kitchenResponse);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            kitchenResponse = kitchen.second->receiveMessage();
        }
        try {
            tmp_avail = std::stoi(kitchenResponse.substr(kitchenResponse.find(":") + 1));
        } catch (const std::exception &e) {
            PlazzaEX(kitchenResponse + ": "s + e.what(), Logger::INFO);
            continue;
        }
        _availSlots[kitchen.first] = _cookNumber - tmp_avail;
        _availSlotsTotal += _cookNumber - tmp_avail;
    }
}

void Reception::_createNewKitchen(std::vector<Pizza> &pizzaToCook, unsigned int pizzaPerKitchen)
{
    Kitchen newKitchen(_cookNumber, _refillTime, _cookingTime);
    std::shared_ptr<MessageQueue> newQueue = std::make_shared<MessageQueue>();
    pid_t newKitchenPid;

    newQueue.get()->openQueue(std::string("/plazzaQueueNumber" + std::to_string(_kitchenMap.size())));
    newKitchenPid = fork();
    if (newKitchenPid == 0) {
        newKitchen.commandQueue = newQueue;
        newKitchen.start();
    } else {
        _kitchenMap[newKitchenPid] = newQueue;
        while (!pizzaToCook.empty()) {
            for (auto &kitchen : _kitchenMap) {
                if (_availSlots[kitchen.first] < (_cookNumber * 2) && !pizzaToCook.empty()){
                    pizzaToCook = _sendPizza(pizzaToCook, pizzaPerKitchen, kitchen.first);
                }
                if (pizzaToCook.empty())
                    break;
            }
        }
    }
}

std::vector<Pizza> Reception::_sendPizza(std::vector<Pizza> &pizzaToCook, int amt, pid_t kitchenPid)
{
    Pizza tmpPizza = pizzaToCook.back();
    for (int x = 0; x < amt && !pizzaToCook.empty(); ++x) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        _kitchenMap[kitchenPid]->sendMessage(pack(tmpPizza));
        pizzaToCook.pop_back();
        tmpPizza = pizzaToCook.back();
    }
    return pizzaToCook;
}

void Reception::_manageOrders(const InputParser &command)
{
    std::vector<Pizza> pizzaToCook = command.getPizza();
    unsigned int pizzaPerKitchen = this->_cookNumber * 2;

    if (pizzaToCook.size() == 0)
        return;
    if (!_kitchenMap.empty()){
        _updateBusyCooks();
        pizzaPerKitchen = _availSlotsTotal + pizzaToCook.size() / _kitchenMap.size();
    }
    if (_kitchenMap.empty() || _isNewKitchenNeeded(pizzaToCook.size())){
        if (_kitchenMap.size() < 9){
            _createNewKitchen(pizzaToCook, pizzaPerKitchen);
            _updateBusyCooks();
        } else
            std::cout << "Could not open more than 9 Kitchens without running the program as root:"
                << "\n\tWaiting for previous orders to finish..." << std::endl;
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
    {
        std::unique_lock<std::mutex> lock(_mutex);
        for (auto x = _kitchenMap.begin(); x != _kitchenMap.end() && !_kitchenMap.empty(); ++x) {
            kill(x->first, SIGTERM);
            _kitchenMap.erase(x->first);
        }
    }
}

void Reception::_kitchenExit(Reception *obj)
{
    while (true) {
        {
            std::unique_lock<std::mutex> lock(obj->_mutex);
            if (obj->_endRun)
                break;
            for (auto it: obj->_kitchenMap) {
                it.second.get()->sendMessage("exit?");
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                std::string message = it.second.get()->receiveMessage();
                while (message.find("exit:") != 0) {
                    it.second.get()->sendMessage(message);
                    message = it.second.get()->receiveMessage();
                }
                if (message == "exit:OK") {
                    kill(it.first, SIGTERM);
                    obj->_kitchenMap.erase(it.first);
                    break;
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Reception::run()
{
    std::string input;
    std::thread exitThread(_kitchenExit, this);

    while (true) {
        if (!std::getline(std::cin, input))
            return;

        if (input == "exit") {
            {
                std::unique_lock<std::mutex> lock(_mutex);
                _endRun = true;
            }
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
    exitThread.join();
    _cleanKitchens();
}
