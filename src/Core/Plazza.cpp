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
#include <unistd.h>
#include <iostream>
#include <utility>

using namespace plazza;

Reception::Reception(size_t cookingTime, size_t cookNumber, size_t refillTime)
{
    _cookingTime = cookingTime;
    _cookNumber = cookNumber;
    _refillTime = refillTime;
}

void Reception::_displayKitchensStatus(void)
{
    std::cout << "Status command not implemented yet." << std::endl;
}

bool Reception::_handleInput(const std::string &input)
{
    InputParser server;
    Kitchen obj(_cookNumber, _refillTime);

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
    Kitchen newKitchen(_cookNumber, _refillTime);
    std::shared_ptr<MessageQueue> newQueue = std::make_shared<MessageQueue>();

    newQueue.get()->openQueue(std::string("/plazzaQueueNumber" + _kitchenQueues.size()));

    pid_t newKitchenPid = fork();

    if (newKitchenPid == 0) {
        newKitchen.commandQueue = newQueue;
        newKitchen.start();
        newKitchen.stop();
    } else {
       _kitchenQueues[newKitchenPid] = newQueue;
       newQueue.get()->sendMessage(command.getCommand());
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
}
