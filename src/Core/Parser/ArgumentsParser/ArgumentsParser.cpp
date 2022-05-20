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
    for (size_t x = 0; x < _arguments.size(); ++x) {

        if (x == 0) {
            float value = 0.0;
            try {
                value = std::stof(_arguments[x]);
            } catch (...) {
                throw InvalidIntCastEX("Multiplier time isn't a float", Logger::CRITICAL);
            }
            if (value < 0.1)
                throw InvalidIntCastEX("Multiplier time isn't a positive float", Logger::CRITICAL);
            _setCookingTime(value);
        } else {
            size_t value = 0;

            try {
                value = std::stoi(_arguments[x]);
            } catch (...) {
                throw InvalidIntCastEX("One of the arguments isn't a int", Logger::CRITICAL);
            }
            if (value <= 0)
                throw InvalidIntCastEX("One of the arguments isn't a positive int", Logger::CRITICAL);
            if (x == 1)
                _setCookNumber(value);
            else
                _setRefillTime(value);
        }
    }
}
