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
    ParserEX("Initialisation of the InputParser class", Logger::INFO);
    _command = "";
    _argumentNumber = 0;
    _separator = ';';
    _arguments.clear();
}

void InputParser::setCommand(const std::string &command)
{
    std::string tmpCommand = command;

    ParserEX("Set the command for the InputParser class", Logger::INFO);
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
    ParserEX("Get the command for the InputParser class", Logger::INFO);
    return (_command);
}

void InputParser::prossessArguments()
{
    std::vector<std::string> tmp = _arguments;
    std::vector<std::string> args;

    ParserEX("Prossess the arguments for the InputParser class", Logger::INFO);
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

bool InputParser::_isValidePizzaName(const std::string &pizza) const
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
        ParserEX("Invalide pizza name in the command", Logger::LOW);
    return (findValidePizza);
}

bool InputParser::_isValidePizzaSize(const std::string &pizzaSize) const
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
        ParserEX("Invalide pizza size in the command", Logger::LOW);
    return (findValidePizzaSize);
}

bool InputParser::_isValidePizzaNumber(const std::string &pizzaNumber) const
{
    bool findValidePizzaNumber = false;
    std::string tmp = pizzaNumber;

    if (tmp.find("x") == 0) {
        tmp.substr(1);
        if (std::atoi(tmp.c_str()) != 0)
            findValidePizzaNumber = true;
    }
    if (!findValidePizzaNumber)
        ParserEX("Invalide pizza number in the command", Logger::LOW);
    return (findValidePizzaNumber);
}

bool InputParser::_isValidePizzaSeparator(const std::string &pizzaSeparator) const
{
    bool findValidePizzaSeparator = true;

    if (pizzaSeparator != ";") {
        ParserEX("Invalide pizza separator in the command", Logger::LOW);
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
            argIsValide = _isValidePizzaName(it);
            break;
        case 1:
            argIsValide = _isValidePizzaSize(it);
            break;
        case 2:
            argIsValide = _isValidePizzaNumber(it);
            break;
        case 3:
            argIsValide = _isValidePizzaSeparator(it);
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
