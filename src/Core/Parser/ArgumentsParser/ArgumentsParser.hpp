/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAA
** File description:
** ArgumentsParser
*/

/// \file src/Parser/ArgumentsParser/ArgumentsParser.hpp

#ifndef ARGUMENTSPARSER_HPP_
#define ARGUMENTSPARSER_HPP_

#include "AParser.hpp"

namespace plazza {
    /// \brief ArgumentsParser class define functions for parsing received arguments
    class ArgumentsParser : public AParser {
        public:
            /// \brief Default Constructor of the ArgumentsParser DO NOT USE
            ArgumentsParser() = default;
            /// \brief Construct the ArgumentsParser with the received arguments
            /// \param ac number of arguments without the binary name (ac - 1)
            /// \param av arguments tab without the binary name (av + 1)
            ArgumentsParser(int, char **);
            /// \brief Destroy the ArgumentsParser object as default.
            ~ArgumentsParser() = default;
            /// \brief Get the cooking Time for the Plazza
            /// \return const size_t &, the cooking time
            inline const float &getCookingTime(void) const
            {
                return _cookingTime;
            };
            /// \brief Get the cooking Time for the Plazza
            /// \return const size_t &, the number of cooks
            inline const size_t &getCookNumber(void) const
            {
                return _cookNumber;
            };
            /// \brief Get the time to refill the fridge for the Plazza
            /// \return const size_t &, the refill time
            inline const size_t &getRefillTime(void) const
            {
                return _refillTimeMs;
            };
            /// \brief Process the arguments given in the char ** (transfers to the inherited member _arguments) by the constructor
            void processArguments();

        private:
            /// \brief Set a new cooking Time with the given parameter
            /// \param newCookingTime the new cooking time to be set
            inline void _setCookingTime(float newCookingTime)
            {
                _cookingTime = newCookingTime;
            };
            /// \brief Set a new Cook Number with the given parameter
            /// \param newCookNumber the new number of cook to be set
            inline void _setCookNumber(size_t newCookNumber)
            {
                _cookNumber = newCookNumber;
            };
            /// \brief Set a new refill time with the given parameter
            /// \param newRefillTime the new refill Time to be set
            inline void _setRefillTime(size_t newRefillTime)
            {
                _refillTimeMs = newRefillTime;
            };

            /// \brief Store the cook Number after processArguments() method is called
            size_t _cookNumber;
            /// \brief Store the cooking Time after processArguments() method is called
            float _cookingTime;
            /// \brief Store the refill Time after processArguments() method is called
            size_t _refillTimeMs;
    };
}// namespace plazza

#endif /* !ARGUMENTSPARSER_HPP_ */
