/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** AParser
*/

#include "AParser.hpp"

void AParser::setCommand(const std::string &command)
{
    std::string tmpCommand = command;

    _command = command;
    while (!tmpCommand.empty()) {
        _arguments.push_back(tmpCommand.substr(0, tmpCommand.find(_separator)));
        tmpCommand = tmpCommand.substr(tmpCommand.find(_separator) + 1);
    }
}

const std::string &AParser::getCommand() const
{
    return (_command);
}

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
