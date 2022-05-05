/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** main
*/

#include "ArgumentsParser.hpp"
#include "MessageQueue/MessageQueue.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    ArgumentsParser args(ac - 1, av + 1);

    args.processArguments();
    return 0;
}
