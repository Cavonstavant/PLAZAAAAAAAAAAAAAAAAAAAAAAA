/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** IParser
*/

#pragma once

#include <string>

class IParser {
    public:
        ~IParser() = default;
        virtual void setCommand(const std::string &) = 0;
        virtual const std::string &getCommand() const = 0;
        virtual const std::size_t &getArgumentNumber() const = 0;
};
