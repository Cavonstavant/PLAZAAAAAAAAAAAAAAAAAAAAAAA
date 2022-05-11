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

Core::Core(size_t cookingTime, size_t cookNumber, size_t refillTime)
{
    _cookingTime = cookingTime;
    _cookNumber = cookNumber;
    _refillTime = refillTime;
}

void Core::run()
{
    std::string input;
    //InputParser server;

    while (true) {
        std::cin >> input;

        std::cout << input << std::endl;
        if (input == "exit")
            break;
    }
}
