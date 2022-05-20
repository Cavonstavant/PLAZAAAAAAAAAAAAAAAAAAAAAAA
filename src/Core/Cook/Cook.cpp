/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Cook
*/

/// \file src/cook/Cook.cpp

#include "Cook.hpp"
#include "PizzaLogger.hpp"
#include <thread>
#include <unistd.h>

using namespace plazza;

Cook::Cook(std::size_t multiplier)
{
    _cookingTime = 0;
    _multiplier = multiplier;
}

Cook::Cook(Pizza pizza, std::size_t multiplier)
{
    _cookingTime = 0;
    _multiplier = multiplier;
    cookPizza(pizza);
}

std::string Cook::pack(const Pizza &pizza)
{
    std::string order = "";

    order.append("name:");
    order.append(std::to_string(pizza.type));
    order.append(";size:");
    order.append(std::to_string(pizza.size));
    order.append(";amount:");
    order.append(std::to_string(pizza.number));
    order.append("\n");
    return (order);
}

void Cook::cookPizza(Pizza pizza)
{
    PizzaLogger::logPizza(pack(pizza), PizzaLogger::Action::ACTION_COOKING_STARTED);
    _pizza = pizza;
    _setCookingTime();
    sleep(_cookingTime);
    PizzaLogger::logPizza(pack(pizza), PizzaLogger::Action::ACTION_COOKING_FINISHED);
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
    _cookingTime = cookingTime * _multiplier;
}
