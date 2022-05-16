/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Cook
*/

#pragma once

#include <string>
#include <vector>
#include "Pizza.hpp"

namespace plazza {
    class Cook {
        public:
            Cook(std::size_t multiplier = 1);
            Cook(const Pizza, std::size_t multiplier = 1);
            ~Cook() = default;
            void setCookingTimeMultipiler(std::size_t multiplier);
            void cookPizza(Pizza pizza);
            bool getCookStatus();
        private:
            void _setCookingTime();
            Pizza _pizza;
            bool _workInProgress;
            std::size_t _multiplier;
    };
}
