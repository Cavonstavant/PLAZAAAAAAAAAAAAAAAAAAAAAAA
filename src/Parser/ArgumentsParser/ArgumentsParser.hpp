/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAA
** File description:
** ArgumentsParser
*/

#ifndef ARGUMENTSPARSER_HPP_
#define ARGUMENTSPARSER_HPP_

#include "AParser.hpp"

#include <vector>
#include <string>

class ArgumentsParser : public AParser{
    public:
        ArgumentsParser(const char **&);

        /// \brief Destroy the AParser object as default.
        ~ArgumentsParser() = default;

        size_t getCookingTime(void) const;
        size_t getCookNumber(void) const;
        size_t getRefillTime(void) const;

        void prossessArguments();
    protected:

    private:

        void setCookingTime(size_t);
        void setCookNumber(size_t cookNumber);
        void setRefillTime(size_t refillTime);

        size_t _cookNumber;
        size_t _cookingTime;
        size_t _refillTimeMs;

};

#endif /* !ARGUMENTSPARSER_HPP_ */
