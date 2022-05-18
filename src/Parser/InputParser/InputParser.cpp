/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** InputParser
*/

/// \file src/Parser/InputParser/InputParser.cpp

#include "InputParser.hpp"
#include "Exception.hpp"
#include <iostream>

using namespace plazza;

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
        if (args[args.size() - 1] != ";")
            args.push_back(";");
    }
    _arguments = args;
    _checkArgumentsValidity();
    _argumentsToPizza();
}

PizzaType InputParser::_getPizzaType(const std::string &type) const
{
    if (type == "regina")
        return (PizzaType::Regina);
    if (type == "margarita")
        return (PizzaType::Margarita);
    if (type == "americana")
        return (PizzaType::Americana);
    if (type == "fantasia")
        return (PizzaType::Fantasia);
    return PizzaType::Regina;
}

PizzaSize InputParser::_getPizzaSize(const std::string &size) const
{
    if (size == "S")
        return (PizzaSize::S);
    if (size == "M")
        return (PizzaSize::M);
    if (size == "L")
        return (PizzaSize::L);
    if (size == "XL")
        return (PizzaSize::XL);
    if (size == "XXL")
        return (PizzaSize::XXL);
    return (PizzaSize::S);
}

void InputParser::_setIngredientsInPizza(Pizza &pizza)
{
    Ingredient ingredient;

    switch (pizza.type) {
        case Margarita:
            ingredient.name = "doe";
            ingredient.number = 1;
            pizza.ingredients.push_back(ingredient);
            ingredient.name = "tomato";
            ingredient.number = 1;
            pizza.ingredients.push_back(ingredient);
            ingredient.name = "gruyere";
            ingredient.number = 1;
            pizza.ingredients.push_back(ingredient);
            break;
        case Regina:
            ingredient.name = "doe";
            ingredient.number = 1;
            pizza.ingredients.push_back(ingredient);
            ingredient.name = "tomato";
            ingredient.number = 1;
            pizza.ingredients.push_back(ingredient);
            ingredient.name = "gruyere";
            ingredient.number = 1;
            pizza.ingredients.push_back(ingredient);
            ingredient.name = "ham";
            ingredient.number = 1;
            pizza.ingredients.push_back(ingredient);
            ingredient.name = "mushrooms";
            ingredient.number = 1;
            pizza.ingredients.push_back(ingredient);
            break;
        case Americana:
            ingredient.name = "doe";
            ingredient.number = 1;
            pizza.ingredients.push_back(ingredient);
            ingredient.name = "tomato";
            ingredient.number = 1;
            pizza.ingredients.push_back(ingredient);
            ingredient.name = "gruyere";
            ingredient.number = 1;
            pizza.ingredients.push_back(ingredient);
            ingredient.name = "steak";
            ingredient.number = 1;
            pizza.ingredients.push_back(ingredient);
            break;
        case Fantasia:
            ingredient.name = "doe";
            ingredient.number = 1;
            pizza.ingredients.push_back(ingredient);
            ingredient.name = "tomato";
            ingredient.number = 1;
            pizza.ingredients.push_back(ingredient);
            ingredient.name = "eggplant";
            ingredient.number = 1;
            pizza.ingredients.push_back(ingredient);
            ingredient.name = "goatCheese";
            ingredient.number = 1;
            pizza.ingredients.push_back(ingredient);
            ingredient.name = "chiefLove";
            ingredient.number = 1;
            pizza.ingredients.push_back(ingredient);
            break;
    }
}

void InputParser::_argumentsToPizza()
{
    Pizza pizza;

    for (std::size_t i = 0; i < _arguments.size(); i++) {
        switch (i % 4) {
            case 0:
                pizza.type = _getPizzaType(_arguments[i]);
                break;
            case 1:
                pizza.size = _getPizzaSize(_arguments[i]);
                break;
            case 2:
                pizza.number = std::atoi(_arguments[i].erase(_arguments[i].begin()).base());
                break;
            case 3:
                _setIngredientsInPizza(pizza);
                _pizza.push_back(pizza);
                break;
        }
    }
}

void InputParser::setCommandSeparator(char sep)
{
    _separator = sep;
}

bool InputParser::_isValidPizzaName(const std::string &pizza) const
{
    const std::string availablePizza[4] = {
            "regina",
            "margarita",
            "americana",
            "fantasia"};
    bool findValidPizza = false;

    for (std::size_t index = 0; index < 4; index++) {
        if (availablePizza[index] == pizza)
            findValidPizza = true;
    }
    if (!findValidPizza)
        ParserEX("Invalid pizza name in the command: " + pizza, Logger::LOW);
    return (findValidPizza);
}

bool InputParser::_isValidPizzaSize(const std::string &pizzaSize) const
{
    const std::string availablePizzaSize[5] = {
            "S",
            "M",
            "L",
            "XL",
            "XXL"};
    bool findValidPizzaSize = false;

    for (std::size_t index = 0; index < 5; index++) {
        if (availablePizzaSize[index] == pizzaSize)
            findValidPizzaSize = true;
    }
    if (!findValidPizzaSize)
        ParserEX("Invalid pizza size in the command: " + pizzaSize, Logger::LOW);
    return (findValidPizzaSize);
}

bool InputParser::_isValidPizzaNumber(const std::string &pizzaNumber) const
{
    bool findValidPizzaNumber = false;
    std::string tmp = pizzaNumber;

    if (tmp.find("x") == 0) {
        tmp.erase(tmp.begin());
        if (std::atoi(tmp.c_str()) != 0)
            findValidPizzaNumber = true;
    }
    if (!findValidPizzaNumber)
        ParserEX("Invalid pizza number in the command: " + pizzaNumber, Logger::LOW);
    return (findValidPizzaNumber);
}

bool InputParser::_isValidPizzaSeparator(const std::string &pizzaSeparator) const
{
    bool findValidPizzaSeparator = true;

    if (pizzaSeparator != ";") {
        ParserEX("Invalid pizza separator in the command: " + pizzaSeparator, Logger::LOW);
        findValidPizzaSeparator = false;
    }
    return (findValidPizzaSeparator);
}

void InputParser::_checkArgumentsValidity()
{
    std::size_t index = 0;
    bool argIsValid = true;
    std::vector<std::string> validArgs;

    for (std::string it: _arguments) {
        if (!argIsValid) {
            if (it == ";") {
                argIsValid = true;
                index = 0;
            }
            continue;
        }
        switch (index % 4) {
            case 0:
                argIsValid = _isValidPizzaName(it);
                break;
            case 1:
                argIsValid = _isValidPizzaSize(it);
                break;
            case 2:
                argIsValid = _isValidPizzaNumber(it);
                break;
            case 3:
                argIsValid = _isValidPizzaSeparator(it);
                break;
        }
        index++;
        if (argIsValid)
            validArgs.push_back(it);
        else {
            while (validArgs.size() > 0 && validArgs.back() != ";")
                validArgs.pop_back();
        }
        if (it == ";") {
            argIsValid = true;
            index = 0;
        }
    }
    _arguments = validArgs;
}

const std::vector<Pizza> &InputParser::getPizza() const
{
    return (_pizza);
}
