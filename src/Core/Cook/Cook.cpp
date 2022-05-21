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

    switch (pizza.type) {
        case Regina:
            order.append("regina");
            break;
        case Americana:
            order.append("americana");
            break;
        case Fantasia:
            order.append("fantasia");
            break;
        case Margarita:
            order.append("margarita");
            break;
    }
    order.append(" of size ");
    switch (pizza.size) {
        case S:
            order.append("S");
            break;
        case M:
            order.append("M");
            break;
        case L:
            order.append("L");
            break;
        case XL:
            order.append("XL");
            break;
        case XXL:
            order.append("XXL");
            break;
    }
    return (order);
}

void Cook::cookPizza(Pizza pizza)
{
    std::string p = pack(pizza);

    PizzaLogger::logPizza(p, PizzaLogger::Action::ACTION_COOKING_STARTED);
    _pizza = pizza;
    _setCookingTime();
    sleep(_cookingTime);
    PizzaLogger::logPizza(p, PizzaLogger::Action::ACTION_COOKING_FINISHED);
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
