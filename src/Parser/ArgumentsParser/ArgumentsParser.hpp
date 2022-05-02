/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAA
** File description:
** ArgumentsParser
*/

#ifndef ARGUMENTSPARSER_HPP_
#define ARGUMENTSPARSER_HPP_

#include "../AParser.hpp"

#include <vector>
#include <string>
#include <exception>

/// \brief ArgumentsParser class define functions for parsing received arguments
class ArgumentsParser : public AParser {
public:
    /// \brief Construct the ArgumentsParser with the received arguments without the binary name (argv + 1)
    ArgumentsParser(char **);
    /// \brief Destroy the ArgumentsParser object as default.
    ~ArgumentsParser() = default;
    /// \brief Get the cooking Time for the Plazza
    /// \return const size_t &, the cooking time
    const size_t &getCookingTime(void) const;
    /// \brief Get the cooking Time for the Plazza
    /// \return const size_t &, the number of cooks
    const size_t &getCookNumber(void) const;
    /// \brief Get the time to refill the fridge for the Plazza
    /// \return const size_t &, the refill time
    const size_t &getRefillTime(void) const;
    /// \brief Process the arguments given in the char ** (transfers to the inherited member _arguments) by the constructor
    void prossessArguments();

private:
    /// \brief Set a new cooking Time with the given parameter
    /// \param newCookingTime the new cooking time to be set
    void setCookingTime(size_t newCookingTime);
    /// \brief Set a new Cook Number with the given parameter
    /// \param newCookNumber the new number of cook to be set
    void setCookNumber(size_t newCookNumber);
    /// \brief Set a new refill time with the given parameter
    /// \param newRefillTime the new refill Time to be set
    void setRefillTime(size_t newRefillTime);

    /// \brief Store the cook Number after processArguments() method is called
    size_t _cookNumber;
    /// \brief Store the cooking Time after processArguments() method is called
    size_t _cookingTime;
    /// \brief Store the refill Time after processArguments() method is called
    size_t _refillTimeMs;
};

#endif /* !ARGUMENTSPARSER_HPP_ */
