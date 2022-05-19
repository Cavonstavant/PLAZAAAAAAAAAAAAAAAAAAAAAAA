/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Cook
*/

/// \file src/cook/Cook.cpp

#include "Cook.hpp"
#include <thread>

extern "C" {
    #include <unistd.h>
}

using namespace plazza;

Cook::Cook(std::size_t multiplier)
{
    _duration = 0;
    _workInProgress = false;
    _multiplier = multiplier;
}

Cook::Cook(Pizza pizza, std::size_t multiplier)
{
    _duration = 0;
    _multiplier = multiplier;
    cookPizza(pizza);
}

void Cook::cookPizza(Pizza pizza)
{
    if (_workInProgress)
        throw PlazzaEX("Cook is already working !", Logger::HIGH);
    _pizza = pizza;
    _setCookingTime();
    sleep(_duration);
}

void Cook::setCookingTimeMultipiler(std::size_t multiplier)
{
    _multiplier = multiplier;
}

void Cook::_setCookingTime()
{
    std::size_t cookingTime = 0;

    switch (_pizza.type) {
        case PizzaType::Regina:
            cookingTime = 2;
            break;
        case PizzaType::Americana:
            cookingTime = 2;
            break;
        case PizzaType::Margarita:
            cookingTime = 1;
            break;
        case PizzaType::Fantasia:
            cookingTime = 4;
            break;
    }
    _duration = cookingTime * _multiplier;
}
