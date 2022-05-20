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
    _busyCooks.resize(_cookNumber);
    _busyCooksTotal = 0;
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
    _sendCommand(server);
    return true;
}

void Reception::_sendCommand(const InputParser &command)
{
    std::vector<Pizza> pizzaToCook = command.getPizza();
    unsigned int pizzaPerKitchen = 0;

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
        newKitchen.stop();
    } else {
        _kitchenMap[newKitchenPid] = newQueue;

        for (std::size_t x = 0; x < pizzaToCook.size(); ++x) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            newQueue.get()->sendMessage(pack(pizzaToCook[x]));
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
