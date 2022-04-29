/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** AParser
*/

#include "AParser.hpp"

const std::size_t &AParser::getArgumentNumber() const
{
    return (_argumentNumber);
}

void AParser::setCommandSeparator(char separator)
{
    _separator = separator;
}

const std::vector<std::string> &AParser::getArguments() const
{
    return (_arguments);
}
