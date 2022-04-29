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
    for (auto it : args)
        std::cout << it << std::endl;
}
