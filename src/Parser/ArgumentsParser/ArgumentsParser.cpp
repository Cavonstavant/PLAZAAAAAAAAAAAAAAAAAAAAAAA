/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAA
** File description:
** ArgumentsParser
*/

/// \file src/Parser/ArgumentsParser/ArgumentsParser.cpp

#include "ArgumentsParser.hpp"
#include <iostream>

ArgumentsParser::ArgumentsParser(char **args)
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
        return;// raise
    }
    for (size_t x = _arguments.size() - 1; x > 0; --x) {

        size_t value = 0;
        try {
            value = std::stoi(_arguments[x]);
        } catch (...) {
            std::cout << "Arg isn't a int" << std::endl;
            return;// raise
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
                std::cout << "Internal Problem on for loop" << std::endl;
                break; // raise
        }

    }
}
