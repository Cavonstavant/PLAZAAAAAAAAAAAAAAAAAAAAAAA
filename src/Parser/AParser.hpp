/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** AParser
*/

#ifndef APARSER_HPP_
#define APARSER_HPP_

#include "IParser.hpp"

class AParser : public IParser {
    public:
        ~AParser() = default;
        void setCommand(const std::string &);
        const std::string &getCommand() const;
        const std::size_t &getArgumentNumber() const;
        virtual void prossessArguments() = 0;
        void setCommandSeparator(char);
        const std::vector<std::string> &getArguments() const;

    protected:
        std::string _command;
        std::size_t _argumentNumber;
        char _separator;
        std::vector<std::string> _arguments;
};

#endif
