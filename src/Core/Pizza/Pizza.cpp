/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Pizza
*/

/// \file src/Core/Pizza.cpp

#include "Pizza.hpp"
#include <iostream>

using namespace plazza;

Ingredient Ingredient::operator-(Ingredient &i)
{
    Ingredient newIngredient;

    if (this->name == i.name) {
        if (this->number < i.number) {
            throw PlazzaEX("There is not enought " + i.name + ".", Logger::LOW);
        } else {
            newIngredient.number = this->number - i.number;
            newIngredient.name = this->name;
        }
    } else {
        throw PlazzaEX("The two ingredients are differents (" + this->name + ", " + i.name + ").", Logger::LOW);
    }
    return (newIngredient);
}

Ingredient Ingredient::operator-(std::size_t &nbr)
{
    Ingredient newIngredient;

    if (this->number < nbr) {
        throw PlazzaEX("There is not enought " + this->name + ".", Logger::LOW);
    } else {
        newIngredient.number = this->number - nbr;
        newIngredient.name = this->name;
    }
    return (newIngredient);
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

Ingredient &Ingredient::operator-=(std::size_t &nbr)
{
    if (this->number < nbr) {
        throw PlazzaEX("There is not enought " + this->name + ".", Logger::LOW);
    } else {
        this->number -= nbr;
    }
    return (*this);
}

std::vector<Ingredient> operator-(std::vector<Ingredient> &lo, std::vector<Ingredient> &ro)
{
    std::vector<Ingredient> tmp(9);
    for (size_t i = 1; i < 9; i++) {
        tmp[i] = lo[i];
    }
    for (std::size_t i = 0; i < tmp.size(); i++) {
        for (std::size_t j = 0; j < ro.size(); j++) {
            if (tmp[i].name == ro[j].name) {
                try {
                    tmp[i] -= ro[i].number;
                } catch (PlazzaException &e) {
                    std::cerr << e.what() << std::endl;
                    throw PlazzaEX("There is not enought ingredient in the vector.", Logger::LOW);
                }
            }
        }
    }
    return (tmp);
}

std::vector<Ingredient> &operator-=(std::vector<Ingredient> &lo, std::vector<Ingredient> &ro)
{
    std::vector<Ingredient> tmp(9);
    for (size_t i = 1; i < 9; i++) {
        tmp[i] = lo[i];
    }
    for (std::size_t i = 1; i < tmp.size(); i++) {
        for (std::size_t j = 0; j < ro.size(); j++) {
            if (tmp[i].name == ro[j].name) {
                try {
                    tmp[i] -= ro[j].number;
                } catch (PlazzaException &e) {
                    std::cerr << e.what() << std::endl;
                    throw PlazzaEX("There is not enought ingredient in the vector.", Logger::LOW);
                }
            }
        }
    }
    for (size_t i = 1; i < 9; i++) {
        lo[i] = tmp[i];
    }
    return (lo);
}

std::vector<Ingredient> operator-(std::vector<Ingredient> &lo, Pizza &ro)
{
    std::vector<Ingredient> tmp;

    try {
        tmp = lo - ro.ingredients;
    } catch (PlazzaException &e) {
        std::cerr << e.what() << std::endl;
        throw PlazzaEX("There is not enought ingredient in the vector.", Logger::LOW);
    }
    return (tmp);
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
