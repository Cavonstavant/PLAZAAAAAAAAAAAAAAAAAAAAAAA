/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** main
*/

#include "Core/Plazza.hpp"
#include "ArgumentsParser.hpp"
#include "MessageQueue/MessageQueue.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    ArgumentsParser args(ac - 1, av + 1);

    try {
        args.processArguments();
    } catch (...) {
        return 84;
    }
    Plazza::Core core (args.getCookingTime(), args.getCookNumber(), args.getRefillTime());

    return 0;
}
