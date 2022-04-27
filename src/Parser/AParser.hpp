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

    private:
        std::string _command;
};