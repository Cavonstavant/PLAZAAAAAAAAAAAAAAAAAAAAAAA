/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser()
{
    _command = "";
}

void Parser::setCommand(const std::string &command)
{
    _command = command;
}

const std::string &Parser::getCommand() const
{
    return (_command);
}

Parser::~Parser()
{
    _command.erase();
}
