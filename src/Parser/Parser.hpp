/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** Parser
*/

#pragma once

#include <string>

class Parser {
public:
    Parser();
    ~Parser();
    void setCommand(const std::string &);
    const std::string &getCommand() const;
private:
    std::string _command;
};
