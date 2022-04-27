/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** InputParser
*/

#include "InputParser.hpp"

InputParser::InputParser()
{
    _command = "";
    _separator = ' ';
    _argumentNumber = 0;
    _arguments.clear();
}

InputParser::~InputParser()
{
}
