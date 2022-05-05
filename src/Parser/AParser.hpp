/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** AParser
*/

/// \file src/Parser/AParser.hpp

#ifndef APARSER_HPP_
#define APARSER_HPP_

#include "IParser.hpp"

/// \brief Aparser class define global fonctions for all parser class in the project
class AParser : public IParser {
    public:
        /// \brief Destroy the AParser object as default.
        ~AParser() = default;
        /// \brief Get the number of arguments in the command.
        /// \return const std::size_t&, the number of arguments.
        const std::size_t &getArgumentNumber() const;
        /// \brief This function will be set differently by the children
        virtual void processArguments() = 0;
        /// \brief Get the a list of all arguments in the command.
        /// \return const std::vector<std::string>& that contain each argument.
        const std::vector<std::string> &getArguments() const;

    protected:
        /// \brief Store the number of arguments in the command.
        std::size_t _argumentNumber;
        /// \brief Store a vector of all argument.
        std::vector<std::string> _arguments;
};

#endif
