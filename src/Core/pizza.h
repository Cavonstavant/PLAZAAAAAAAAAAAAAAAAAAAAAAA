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

namespace pizza {
    typedef pizzaSize_e pizzaSize_t;
    typedef pizza_s pizza_t;

    /// \brief Enumeration for available pizza size.
    enum pizzaSize_e {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16,
    };

    /// \brief Structure for pizza.
    struct pizza_s {
        /// \brief std::string Name of the pizza.
        std::string name;
        /// \brief enum pizzaSize_e Size of the pizza.
        enum pizzaSize_e size;
        /// \brief std::string Number of pizza.
        std::size_t number;
    };
}
#endif /* !PIZZA_H_ */