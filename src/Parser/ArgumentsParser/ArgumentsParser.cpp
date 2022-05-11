/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAA
** File description:
** ArgumentsParser
*/

/// \file src/Parser/ArgumentsParser/ArgumentsParser.cpp

#include "ArgumentsParser.hpp"
#include "Exception.hpp"
#include <iostream>
#include <string>

using namespace plazza;

ArgumentsParser::ArgumentsParser(int ac, char **args)
{
    for (size_t x = 0; args[x]; ++x) {
        _arguments.push_back(std::string(args[x]));
    }
    _argumentNumber = ac;
}

void ArgumentsParser::processArguments()
{
    if (_argumentNumber != 3) {
        throw InvalidNbrArgumentsEX("You need 3 arguments.\n", Logger::CRITICAL);
    }
    for (size_t x = _arguments.size() - 1; x > 0; --x) {

        size_t value = 0;
        try {
            value = std::stoi(_arguments[x]);
        } catch (...) {
            throw InvalidIntCastEX("One of the arguments isn't a int", Logger::CRITICAL);
        }
        switch (x) {
        case 2:
            _setRefillTime(value);
            break;
        case 1:
            _setCookNumber(value);
            break;
        case 0:
            _setCookingTime(value);
            break;
        default:
            throw VeryStupidUserEX("That's not possible, or you've broke my program...", Logger::CRITICAL);
        }
    }
}
