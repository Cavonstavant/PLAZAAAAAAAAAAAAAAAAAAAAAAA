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
            Cook();
            Cook(const Pizza);
            ~Cook() = default;
            void setCookingTimeMultipiler();
        private:
            Pizza _pizza;
            bool _workInProgress;
            std::size_t _multiplier;
    };
}
