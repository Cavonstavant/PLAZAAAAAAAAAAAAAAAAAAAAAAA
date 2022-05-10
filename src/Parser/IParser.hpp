/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** IParser
*/

/// \file src/Parser/IParser.hpp

#ifndef IPARSER_HPP_
#define IPARSER_HPP_

#include <string>
#include <vector>

namespace plazza {
/// \brief Base parser class for all parser class in the project
class IParser {
public:
    /// \brief Destroy the IParser object as default
    ~IParser() = default;
    /// \brief Get the number of arguments in the command.
    /// \return const std::size_t&, the number of arguments.
    virtual const std::size_t &getArgumentNumber() const = 0;
    /// \brief This function will be set differently by the children
    virtual void processArguments() = 0;
    /// \brief Get the a list of all arguments in the command.
    /// \return const std::vector<std::string>& that contain each argument.
    virtual const std::vector<std::string> &getArguments() const = 0;
};
}

#endif
