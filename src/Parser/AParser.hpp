/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** AParser
*/

#ifndef APARSER_HPP_
#define APARSER_HPP_

#include "IParser.hpp"

/**
 * @brief The AParser inherit of IParser class.
 *
 */
class AParser : public IParser {
    public:
        /**
         * @brief Destroy the AParser object as default.
         *
         */
        ~AParser() = default;
        /**
         * @brief Set the command that will be parsed.
         *
         */
        void setCommand(const std::string &);
        /**
         * @brief Get the command previously set.
         *
         * @return const std::string& of the command.
         * It return an empty std::string in case of undefined command.
         */
        const std::string &getCommand() const;
        /**
         * @brief Get the number of arguments in the command.
         *
         * @return const std::size_t&, the number of arguments.
         */
        const std::size_t &getArgumentNumber() const;
        virtual void prossessArguments() = 0;
        /**
         * @brief Set a char that will be the separator on each command.
         *
         */
        void setCommandSeparator(char);
        /**
         * @brief Get the a list of all arguments in the command.
         *
         * @return const std::vector<std::string>& that contain each argument.
         */
        const std::vector<std::string> &getArguments() const;

    protected:
        /**
         * @brief Store the command that will be prossess.
         *
         */
        std::string _command;
        /**
         * @brief Store the number of arguments in the command.
         *
         */
        std::size_t _argumentNumber;
        /**
         * @brief Store the separator of each argument.
         *
         */
        char _separator;
        /**
         * @brief Store a vector of all argument.
         * 
         */
        std::vector<std::string> _arguments;
};

#endif
