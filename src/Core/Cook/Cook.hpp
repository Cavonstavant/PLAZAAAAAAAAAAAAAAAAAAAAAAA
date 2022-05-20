/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Cook
*/

/// \file src/cook/Cook.hpp

#ifndef COOK_H_
#define COOK_H_

#include "Pizza.hpp"
#include <string>
#include <vector>

namespace plazza {
    /// \brief Cook class is use to cook a pizza with a duration time.
    class Cook {
        public:
            /// \brief Default constructor
            /// \param std::size_t Set a multiplier for the cooking time.
            Cook(std::size_t multiplier = 1);
            /// \brief Constructor with a pizza as parameter.
            /// \param Pizza Set the pizza to be cook.
            /// \param std::size_t Set a multiplier for the cooking time.
            Cook(const Pizza, std::size_t multiplier = 1);
            /// \brief Default destructor.
            ~Cook() = default;
            /// \brief Set the cooking time multiplier.
            /// \param std::size_t Coef of the cooking time.
            void setCookingTimeMultipiler(std::size_t multiplier);
            /// \brief Set a pizza to be cook.
            /// \param Pizza The pizza to be cook.
            void cookPizza(Pizza pizza);
            /// \brief Pack a pizza to a std::string.
            /// \param const Pizza &The pizza to be pack.
            /// \return std::string The pizza pack.
            std::string pack(const Pizza &);

        private:
            /// \brief Set the cooking time depending of the pizza to be cook.
            void _setCookingTime();
            /// \brief Store the pizza to be cook.
            Pizza _pizza;
            /// \brief Store the multiplier of cooking time.
            std::size_t _multiplier;
            /// \brief Store the duration of the cooking time of the pizza.
            std::size_t _cookingTime;
    };
}// namespace plazza

#endif
