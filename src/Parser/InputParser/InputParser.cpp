/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** InputParser
*/

#include "InputParser.hpp"
#include <iostream>

InputParser::InputParser()
{
    _command = "";
    _argumentNumber = 0;
    _separator = ';';
    _arguments.clear();
}

void InputParser::setCommand(const std::string &command)
{
    std::string tmpCommand = command;

    _command = command;
    while (!tmpCommand.empty()) {
        while (tmpCommand.find(_separator) == 0)
            tmpCommand = tmpCommand.substr(1);
        if (tmpCommand.empty())
            break;
        _arguments.push_back(tmpCommand.substr(0, tmpCommand.find(_separator)));
        if (tmpCommand.find(_separator) < tmpCommand.size())
            tmpCommand = tmpCommand.substr(tmpCommand.find(_separator));
        else
            tmpCommand.clear();
        _argumentNumber++;
    }
}

const std::string &InputParser::getCommand() const
{
    return (_command);
}

void InputParser::prossessArguments()
{
    std::vector<std::string> tmp = _arguments;
    std::vector<std::string> args;

    setCommandSeparator(' ');
    for (auto it : tmp) {
        _arguments.clear();
        setCommand(it);
        for (auto arg : _arguments) {
            args.push_back(arg);
        }
        args.push_back(";");
    }
    _arguments = args;
    _checkArgumentsValidity();
}

bool isValidePizza(const std::string &pizza)
{
    const std::string availablePizza[4] = {
        "Regina",
        "Margarita",
        "Americana",
        "Fantasia"
    };
    bool findValidePizza = false;

    for (std::size_t index = 0; index < 4; index++) {
        if (availablePizza[index] == pizza)
            findValidePizza = true;
    }
    if (!findValidePizza)
        std::cout << "Invalide pizza name: " << pizza << std::endl;
    return (findValidePizza);
}

bool isValidePizzaSize(const std::string &pizzaSize)
{
    const std::string availablePizzaSize[5] = {
        "S",
        "M",
        "L",
        "XL",
        "XXL"
    };
    bool findValidePizzaSize = false;

    for (std::size_t index = 0; index < 5; index++) {
        if (availablePizzaSize[index] == pizzaSize)
            findValidePizzaSize = true;
    }
    if (!findValidePizzaSize)
        std::cout << "Invalide pizza size: " << pizzaSize << std::endl;
    return (findValidePizzaSize);
}

bool isValidePizzaNumber(const std::string &pizzaNumber)
{
    bool findValidePizzaNumber = false;

    if (pizzaNumber == "x1")
        findValidePizzaNumber = true;
    if (!findValidePizzaNumber)
        std::cout << "Invalide pizza number: " << pizzaNumber << std::endl;
    return (findValidePizzaNumber);
}

bool isValidePizzaSeparator(const std::string &pizzaSeparator)
{
    bool findValidePizzaSeparator = true;

    if (pizzaSeparator != ";") {
        std::cout << "Invalide pizza separator: " << pizzaSeparator << std::endl;
        findValidePizzaSeparator = false;
    }
    return (findValidePizzaSeparator);
}

void InputParser::_checkArgumentsValidity() const
{
    std::size_t index = 0;
    bool argIsValide = true;

    for (std::string it : _arguments) {
        if (!argIsValide) {
            if (it == ";") {
                argIsValide = true;
                index = 0;
            }
            continue;
        }
        switch (index % 4) {
            case 0:
                argIsValide = isValidePizza(it);
                break;
            case 1:
                argIsValide = isValidePizzaSize(it);
                break;
            case 2:
                argIsValide = isValidePizzaNumber(it);
                break;
            case 3:
                argIsValide = isValidePizzaSeparator(it);
                break;
        }
        index++;
        if (it == ";") {
            argIsValide = true;
            index = 0;
        }
    }
}
