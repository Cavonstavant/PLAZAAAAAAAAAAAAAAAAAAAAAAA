/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Pizza
*/

#include "Pizza.hpp"

using namespace plazza;

Ingredient &Ingredient::operator-(Ingredient &i)
{
    if (this->name == i.name) {
        if (this->number < i.number) {
            throw PlazzaEX("There is not enought " + i.name + ".", Logger::LOW);
        } else {
            this->number -= i.number;
        }
    } else {
        throw PlazzaEX("The two ingredients are differents (" + this->name + ", " + i.name + ").", Logger::LOW);
    }
    return (*this);
}

Ingredient &Ingredient::operator-(std::size_t &number)
{
    if (this->number < number) {
        throw PlazzaEX("There is not enought " + this->name + ".", Logger::LOW);
    } else {
        this->number -= number;
    }
    return (*this);
}

Ingredient &Ingredient::operator-=(Ingredient &i)
{
    if (this->name == i.name) {
        if (this->number < i.number) {
            throw PlazzaEX("There is not enought " + i.name + ".", Logger::LOW);
        } else {
            this->number -= i.number;
        }
    } else {
        throw PlazzaEX("The two ingredients are differents (" + this->name + ", " + i.name + ").", Logger::LOW);
    }
    return (*this);
}

Ingredient &Ingredient::operator-=(std::size_t &number)
{
    if (this->number < number) {
        throw PlazzaEX("There is not enought " + this->name + ".", Logger::LOW);
    } else {
        this->number -= number;
    }
    return (*this);
}