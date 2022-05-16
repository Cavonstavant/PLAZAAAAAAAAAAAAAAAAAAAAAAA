/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Cook
*/

#include "Cook.hpp"

using namespace plazza;

Cook::Cook(std::size_t multiplier)
{
    _workInProgress = false;
    _multiplier = multiplier;
}

Cook::Cook(Pizza pizza, std::size_t multiplier)
{
    _multiplier = multiplier;
    cookPizza(pizza);
}

void Cook::cookPizza(Pizza pizza)
{
    // set the start timer of the cook
    _pizza = pizza;
    _workInProgress = true;
}

void Cook::setCookingTimeMultipiler(std::size_t multiplier)
{
    _multiplier = multiplier;
}

bool Cook::getCookStatus()
{
    // Check if the cook has finished and update the _workInProgress
    return (_workInProgress);
}

void Cook::_setCookingTime()
{
    std::size_t cookingTime = 0;

    switch (_pizza.type)
    {
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
    // set the duration of pizza cook
}
