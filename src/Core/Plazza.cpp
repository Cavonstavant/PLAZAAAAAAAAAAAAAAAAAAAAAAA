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

Reception::Reception(float cookingTime, size_t cookNumber, size_t refillTime)
{
    _cookingTime = cookingTime;
    _cookNumber = cookNumber;
    _refillTime = refillTime;
    _endRun = false;
}

int Reception::_isAvailableSlots(std::string message)
{
    int slots = 0;

    if (message.find("avail_slots:") == 0) {
        message = message.substr(message.find(":") + 1);
        try {
            slots = std::stoi(message);
        } catch (std::exception &e) {
            std::cerr << "Error:" << e.what() << std::endl;
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
            std::cout << "Available cooks: " << cookAvailable << "/" << _cookNumber << std::endl;
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
    _sendCommand(server);
    return true;
}

void Reception::_sendCommand(const InputParser &command)
{
    std::vector<Pizza> pizzaToCook = command.getPizza();

    {
        std::unique_lock<std::mutex> lock(_mutex);
        if (pizzaToCook.size() == 0)
            return;
        if (_kitchenMap.size() == 9) {
            MessageQueueEx("You can not open more than 9 Kitchens", Logger::MEDIUM);
            return;
        }

        Kitchen newKitchen(_cookNumber, _refillTime, _cookingTime);
        std::shared_ptr<MessageQueue> newQueue = std::make_shared<MessageQueue>();

        newQueue.get()->openQueue(std::string("/plazzaQueueNumber" + std::to_string(_kitchenMap.size())));

        pid_t newKitchenPid = fork();

        if (newKitchenPid == 0) {
            newKitchen.commandQueue = newQueue;
            newKitchen.start();
        } else {
            _kitchenMap[newKitchenPid] = newQueue;

            for (std::size_t x = 0; x < pizzaToCook.size(); ++x) {
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                newQueue.get()->sendMessage(pack(pizzaToCook[x]));
            }
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
