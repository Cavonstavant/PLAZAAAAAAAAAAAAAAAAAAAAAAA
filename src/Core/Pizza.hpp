/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** pizza
*/

/// \file src/Core/pizza.h

#ifndef PIZZA_H_
#define PIZZA_H_

#include <string>
#include "Exception.hpp"

namespace plazza {

    /// \brief Enumeration for available pizza type.
    enum PizzaType {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8,
    };

    /// \brief Enumeration for available pizza size.
    enum PizzaSize {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16,
    };

    /// \brief Structure for pizza.
    struct Pizza {
            /// \brief PizzaType Type of the pizza.
            PizzaType type;
            /// \brief PizzaSize Size of the pizza.
            PizzaSize size;
            /// \brief std::size_t Number of pizza.
            std::size_t number;
    };

    /// \brief Structure for ingredient.
    struct Ingredient {
        /// \brief Name of the ingredient.
        std::string name;
        /// \brief Number of ingredient.
        std::size_t number;
        /// \brief Overload the operator- for the structure Ingredient.
        /// \brief It will decrement the ingredient number by the ingredient number passed as parameter.
        /// \param Ingredient & Reference to the ingredient.
        /// \return Ingredient after remove Ingredient number passed as parameter.
        Ingredient &operator-(Ingredient &i) {
            if (this->name == i.name) {
                if (this->number < i.number) {
                    throw PlazzaEX("There is not enought " + i.name + ".", Logger::LOW);
                } else {
                    this->number -= i.number;
                }
            } else {
                throw PlazzaEX("The two ingredients are differents (" + this->name + ", " + i.name + ").", Logger::LOW);
            }
        }
        /// \brief Overload the operator- for the structure Ingredient.
        /// \brief It will decrement the ingredient number by the number passed as parameter.
        /// \param std::size_t & Reference to the number to remove.
        /// \return Ingredient after remove number passed as parameter.
        Ingredient &operator-(std::size_t &number) {
            if (this->number < number) {
                throw PlazzaEX("There is not enought " + this->name + ".", Logger::LOW);
            } else {
                this->number -= number;
            }
        }
    };
}// namespace plazza

#endif /* !PIZZA_H_ */
