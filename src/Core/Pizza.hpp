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
}// namespace plazza

#endif /* !PIZZA_H_ */
