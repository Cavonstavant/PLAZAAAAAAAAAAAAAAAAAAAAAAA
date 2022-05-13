/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Pizza
*/

#include "Pizza.hpp"
#include <iostream>

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

std::vector<Ingredient> &operator-(std::vector<Ingredient> &lo, std::vector<Ingredient> &ro)
{
    std::vector<Ingredient> tmp = lo;

    for (std::size_t i = 0; i < tmp.size(); i++) {
        for (std::size_t j = 0; j < ro.size(); j++) {
            if (tmp[i].name == ro[j].name) {
                try {
                    tmp[i] -= ro[i];
                } catch (PlazzaException &e) {
                    std::cerr << e.what() << std::endl;
                    throw PlazzaEX("There is not enought ingredient in the vector.", Logger::LOW);
                }
            }
        }
    }
    lo = tmp;
    return (lo);
}

std::vector<Ingredient> &operator-=(std::vector<Ingredient> &lo, std::vector<Ingredient> &ro)
{
    std::vector<Ingredient> tmp = lo;

    for (std::size_t i = 0; i < tmp.size(); i++) {
        for (std::size_t j = 0; j < ro.size(); j++) {
            if (tmp[i].name == ro[j].name) {
                try {
                    tmp[i] -= ro[i];
                } catch (PlazzaException &e) {
                    std::cerr << e.what() << std::endl;
                    throw PlazzaEX("There is not enought ingredient in the vector.", Logger::LOW);
                }
            }
        }
    }
    lo = tmp;
    return (lo);
}

std::vector<Ingredient> &operator-(std::vector<Ingredient> &lo, Pizza &ro)
{
    try {
        lo -= ro.ingredients;
    } catch (PlazzaException &e) {
        std::cerr << e.what() << std::endl;
        throw PlazzaEX("There is not enought ingredient in the vector.", Logger::LOW);
    }
    return (lo);
}

std::vector<Ingredient> &operator-=(std::vector<Ingredient> &lo, Pizza &ro)
{
    try {
        lo -= ro.ingredients;
    } catch (PlazzaException &e) {
        std::cerr << e.what() << std::endl;
        throw PlazzaEX("There is not enought ingredient in the vector.", Logger::LOW);
    }
    return (lo);
}
