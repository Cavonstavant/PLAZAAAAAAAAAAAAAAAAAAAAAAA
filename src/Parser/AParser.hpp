/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** AParser
*/

#pragma once

#include "IParser.hpp"

class AParser : public IParser {
    public:
        AParser();
        ~AParser();
        void setCommand(const std::string &);
        const std::string &getCommand() const;
        const std::size_t &getArgumentNumber() const = 0;

    protected:
        std::string _command;
        std::size_t _argumentNumber;
};
