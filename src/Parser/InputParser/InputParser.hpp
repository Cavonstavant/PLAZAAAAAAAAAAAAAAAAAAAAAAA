/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** InputParser
*/

/// \file src/Parser/InputParser/InputParser.hpp

#ifndef INPUTPARSER_HPP_
#define INPUTPARSER_HPP_

#include "AParser.hpp"
#include "Pizza.hpp"

namespace plazza {
/// \brief InputParser is a class used to parse command of pizza while the program is running
class InputParser : public AParser {
public:
    /// \brief Create the InputParser instance and define all variables
    InputParser();
    /// \brief Destroy the InputParser instance and destroy all variables
    ~InputParser() = default;
    /// \brief Set the command that will be parsed.
    /// \param const std::string & is the command string
    void setCommand(const std::string &);
    /// \brief Get the command previously set.
    /// \return const std::string& of the command.
    /// It return an empty std::string in case of undefined command.
    const std::string &getCommand() const;
    /// \brief Process the argument to set them in a form usefull for the program
    void processArguments() override;
    /// \brief Set the separator for the command
    /// \param const char Separator char
    void setCommandSeparator(const char);
    /// \brief Get a vector of valid pizza.
    /// \return std::vector<Pizza> &.
    const std::vector<Pizza> &getPizza() const;

private:
    /// \brief Store the command that will be process.
    std::string _command;
    /// \brief Store a vector of valid pizza.
    std::vector<Pizza> _pizza;
    /// \brief Store the separator that will use for processArgument.
    char _separator;
    /// \brief Check the validity of all arguments of the command.
    /// It will print a message if an error occured.
    void _checkArgumentsValidity();
    /// \brief Check if the pizza name passed as parameter is valid.
    /// It will print a message if an error occured.
    /// \param const std::string & is the pizza name.
    /// \return true if it's std::string is a valid pizza name, false otherwise.
    bool _isValidPizzaName(const std::string &) const;
    /// \brief Check if the pizza size passed as parameter is valid.
    /// It will print a message if an error occured.
    /// \param const std::string & is the pizza size.
    /// \return true if it's std::string is a valid pizza size, false otherwise.
    bool _isValidPizzaSize(const std::string &) const;
    /// \brief Check if the pizza number passed as parameter is valid.
    /// It will print a message if an error occured.
    /// \param const std::string & is the pizza number.
    /// \return true if it's std::string is a valid pizza number, false otherwise.
    bool _isValidPizzaNumber(const std::string &) const;
    /// \brief Check if the pizza separator passed as parameter is valid.
    /// It will print a message if an error occured.
    /// \param const std::string & is the pizza separator.
    /// \return true if it's std::string is a valid pizza separator, false otherwise.
    bool _isValidPizzaSeparator(const std::string &) const;
    /// \brief Convert arguments to pizza.
    void _argumentsToPizza();
    /// \brief Get the type of a pizza from is name.
    /// \param std::string Name of the pizza.
    /// \return PizzaType Type of the pizza.
    PizzaType _getPizzaType(const std::string &type) const;
    /// \brief Get the size of a pizza from is size.
    /// \param std::string Size of the pizza.
    /// \return PizzaSize Size of the pizza.
    PizzaSize _getPizzaSize(const std::string &size) const;
    void _setIngredientsInPizza(Pizza &pizza);
};
}// namespace plazza

#endif
