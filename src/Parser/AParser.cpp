/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** AParser
*/

#include "AParser.hpp"

void AParser::setCommand(const std::string &command)
{
    _command = command;
}

const std::string &AParser::getCommand() const
{
    return (_command);
}

const std::size_t &AParser::getArgumentNumber() const
{
    return (_argumentNumber);
}
