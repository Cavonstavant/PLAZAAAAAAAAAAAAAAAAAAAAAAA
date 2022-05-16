/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Cook
*/

#include "Cook.hpp"

using namespace plazza;

Cook::Cook()
{
    _workInProgress = false;
}

Cook::Cook(Pizza pizza)
{
    _pizza = pizza;
    _workInProgress = true;
}

void Cook::setCookingTimeMultiplier(std::size_t multiplier)
{
    _multiplier = multiplier;
}