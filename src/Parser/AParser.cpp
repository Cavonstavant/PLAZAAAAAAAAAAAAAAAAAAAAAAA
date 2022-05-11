/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** AParser
*/

#include "AParser.hpp"

using namespace plazza;

const std::size_t &AParser::getArgumentNumber() const
{
    return (_argumentNumber);
}

const std::vector<std::string> &AParser::getArguments() const
{
    return (_arguments);
}
