/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAA
** File description:
** ArgumentsParser
*/

#include "ArgumentsParser.hpp"

ArgumentsParser::ArgumentsParser(const char **& args)
{
    for (size_t x = 0; args[x]; ++x) {
        _arguments.push_back(std::string(args[x]));
    }
    _argumentNumber = _arguments.size();
}

void ArgumentsParser::prossessArguments()
{
    if (_argumentNumber != 3)
        return; //Throw an Exception
    for (size_t x = _arguments.size() - 1; x > 0; --x) {
        try {
            size_t value = std::stoi(_arguments[x]);

            switch (x) {
            case 3:
                setRefillTime(value);
                break;
            case 2:
                setCookNumber(value);
                break;
            case 1:
                setCookingTime(value);
                break;
            default:
                break; // raise
            }
        } catch (...) {
            return; //raise
        }
    }
}

size_t ArgumentsParser::getCookingTime(void) const
{
    return _cookingTime;
}

size_t ArgumentsParser::getRefillTime(void) const
{
    return _refillTimeMs;
}

size_t ArgumentsParser::getCookNumber(void) const
{
    return _cookNumber;
}

void ArgumentsParser::setCookingTime(size_t cookingTime)
{
    _cookingTime = cookingTime;
}

void ArgumentsParser::setRefillTime(size_t refillTime)
{
    _refillTimeMs = refillTime;
}

void ArgumentsParser::setCookNumber(size_t cookNumber)
{
    _cookNumber = cookNumber;
}