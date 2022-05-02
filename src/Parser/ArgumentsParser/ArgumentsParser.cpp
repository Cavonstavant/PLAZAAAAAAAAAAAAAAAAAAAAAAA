/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAA
** File description:
** ArgumentsParser
*/

#include "ArgumentsParser.hpp"
#include <iostream>

ArgumentsParser::ArgumentsParser(char ** args)
{
    for (size_t x = 0; args[x]; ++x) {
        _arguments.push_back(std::string(args[x]));
    }
    _argumentNumber = _arguments.size();
}

void ArgumentsParser::prossessArguments()
{
    if (_argumentNumber != 3) {
        std::cout << "Invalid Number of Args" << std::endl;
        return; // raise
    }
    for (size_t x = _arguments.size() - 1; x > 0; --x) {
        try {
            size_t value = std::stoi(_arguments[x]);

            switch (x) {
            case 2:
                setRefillTime(value);
                break;
            case 1:
                setCookNumber(value);
                break;
            case 0:
                setCookingTime(value);
                break;
            default:
                std::cout << "Problem" << std::endl;
                break; // raise
            }
        } catch (...) {
            std::cout << "Arg isn't a int" << std::endl;
            return; // raise
        }
    }
}

const size_t &ArgumentsParser::getCookingTime(void) const
{
    return _cookingTime;
}

const size_t &ArgumentsParser::getRefillTime(void) const
{
    return _refillTimeMs;
}

const size_t &ArgumentsParser::getCookNumber(void) const
{
    return _cookNumber;
}

void ArgumentsParser::setCookingTime(size_t newCookingTime)
{
    _cookingTime = newCookingTime;
}

void ArgumentsParser::setRefillTime(size_t newRefillTime)
{
    _refillTimeMs = newRefillTime;
}

void ArgumentsParser::setCookNumber(size_t newCookNumber)
{
    _cookNumber = newCookNumber;
}