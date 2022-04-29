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
        /// \brief Prossess the argument to set them in a form usefull for the program
        void prossessArguments() override;
};

#endif
