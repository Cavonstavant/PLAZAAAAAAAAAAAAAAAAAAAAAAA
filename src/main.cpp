/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** main
*/

#include "ArgumentsParser.hpp"
#include "MessageQueue/MessageQueue.hpp"
#include "Plazza.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    plazza::ArgumentsParser args(ac - 1, av + 1);

    args.processArguments();

    plazza::Core core(args.getCookingTime(), args.getCookNumber(), args.getRefillTime());

    core.run();

    return 0;
}
