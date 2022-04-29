/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** InputParser
*/

#ifndef INPUTPARSER_HPP_
#define INPUTPARSER_HPP_

#include "../AParser.hpp"

/// \brief InputParser is a class use to parse command of pizza while the program is running
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
        /// \brief Prossess the argument to set them in a form usefull for the program
        void prossessArguments() override;

    private:
        /// \brief Store the command that will be prossess.
        std::string _command;
        /// \brief Check the validity of all arguments of the command.
        /// It will print a message if an error occured.
        void _checkArgumentsValidity();
        /// \brief Check if the pizza name passed as parameter is valide.
        /// It will print a message if an error occured.
        /// \param const std::string & is the pizza name.
        bool _isValidePizzaName(const std::string &) const;
        /// \brief Check if the pizza size passed as parameter is valide.
        /// It will print a message if an error occured.
        /// \param const std::string & is the pizza size.
        bool _isValidePizzaSize(const std::string &) const;
        /// \brief Check if the pizza number passed as parameter is valide.
        /// It will print a message if an error occured.
        /// \param const std::string & is the pizza number.
        bool _isValidePizzaNumber(const std::string &) const;
        /// \brief Check if the pizza separator passed as parameter is valide.
        /// It will print a message if an error occured.
        /// \param const std::string & is the pizza separator.
        bool _isValidePizzaSeparator(const std::string &) const;
};

#endif
