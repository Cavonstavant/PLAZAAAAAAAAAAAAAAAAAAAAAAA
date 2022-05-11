/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAA
** File description:
** Plazza
*/

/// \file src/Core/Plazza.cpp

#include "Plazza.hpp"
#include "InputParser.hpp"
#include <iostream>
#include <string>

using namespace plazza;

Reception::Reception(size_t cookingTime, size_t cookNumber, size_t refillTime)
{
    _cookingTime = cookingTime;
    _cookNumber = cookNumber;
    _refillTime = refillTime;
}

void Reception::run()
{
    std::string input;
    InputParser server;

    while (true) {
        std::cin >> input;

        if (input == "exit")
            break;
    }
}
