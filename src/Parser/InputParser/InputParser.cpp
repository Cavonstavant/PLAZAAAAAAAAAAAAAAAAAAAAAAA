/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** InputParser
*/

#include "InputParser.hpp"
#include "Exception.hpp"
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

void InputParser::processArguments()
{
    std::vector<std::string> tmp = _arguments;
    std::vector<std::string> args;

    setCommandSeparator(' ');
    for (auto it: tmp) {
        _arguments.clear();
        setCommand(it);
        for (auto arg: _arguments) {
            args.push_back(arg);
        }
        args.push_back(";");
    }
    _arguments = args;
    _checkArgumentsValidity();
}

bool InputParser::_isValidPizzaName(const std::string &pizza) const
{
    const std::string availablePizza[4] = {
            "Regina",
            "Margarita",
            "Americana",
            "Fantasia"};
    bool findValidePizza = false;

    for (std::size_t index = 0; index < 4; index++) {
        if (availablePizza[index] == pizza)
            findValidePizza = true;
    }
    if (!findValidePizza)
        ParserEX("Invalid pizza name in the command: " + pizza, Logger::LOW);
    return (findValidePizza);
}

bool InputParser::_isValidPizzaSize(const std::string &pizzaSize) const
{
    const std::string availablePizzaSize[5] = {
            "S",
            "M",
            "L",
            "XL",
            "XXL"};
    bool findValidePizzaSize = false;

    for (std::size_t index = 0; index < 5; index++) {
        if (availablePizzaSize[index] == pizzaSize)
            findValidePizzaSize = true;
    }
    if (!findValidePizzaSize)
        ParserEX("Invalid pizza size in the command: " + pizzaSize, Logger::LOW);
    return (findValidePizzaSize);
}

bool InputParser::_isValidPizzaNumber(const std::string &pizzaNumber) const
{
    bool findValidePizzaNumber = false;
    std::string tmp = pizzaNumber;

    if (tmp.find("x") == 0) {
        tmp.substr(1);
        if (std::atoi(tmp.c_str()) != 0)
            findValidePizzaNumber = true;
    }
    if (!findValidePizzaNumber)
        ParserEX("Invalid pizza number in the command: " + pizzaNumber, Logger::LOW);
    return (findValidePizzaNumber);
}

bool InputParser::_isValidPizzaSeparator(const std::string &pizzaSeparator) const
{
    bool findValidePizzaSeparator = true;

    if (pizzaSeparator != ";") {
        ParserEX("Invalid pizza separator in the command: " + pizzaSeparator, Logger::LOW);
        findValidePizzaSeparator = false;
    }
    return (findValidePizzaSeparator);
}

void InputParser::_checkArgumentsValidity()
{
    std::size_t index = 0;
    bool argIsValide = true;
    std::vector<std::string> valideArgs;

    for (std::string it: _arguments) {
        if (!argIsValide) {
            if (it == ";") {
                argIsValide = true;
                index = 0;
            }
            continue;
        }
        switch (index % 4) {
            case 0:
                argIsValide = _isValidPizzaName(it);
                break;
            case 1:
                argIsValide = _isValidPizzaSize(it);
                break;
            case 2:
                argIsValide = _isValidPizzaNumber(it);
                break;
            case 3:
                argIsValide = _isValidPizzaSeparator(it);
                break;
        }
        index++;
        if (argIsValide)
            valideArgs.push_back(it);
        else {
            while (valideArgs.size() > 0 && valideArgs.back() != ";")
                valideArgs.pop_back();
        }
        if (it == ";") {
            argIsValide = true;
            index = 0;
        }
    }
    _arguments = valideArgs;
}
