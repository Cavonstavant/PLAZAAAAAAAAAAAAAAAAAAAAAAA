/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** IParser
*/

#ifndef IPARSER_HPP_
#define IPARSER_HPP_

#include <string>
#include <vector>

class IParser {
    public:
        ~IParser() = default;
        virtual void setCommand(const std::string &) = 0;
        virtual const std::string &getCommand() const = 0;
        virtual const std::size_t &getArgumentNumber() const = 0;
        virtual void prossessArguments() = 0;
        virtual void setCommandSeparator(char) = 0;
        virtual const std::vector<std::string> &getArguments() const = 0;
};

#endif
