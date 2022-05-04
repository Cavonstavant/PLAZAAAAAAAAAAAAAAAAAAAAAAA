/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** main
*/

#include "ArgumentsParser.hpp"
#include "MessageQueue/MessageQueue.hpp"
#include <string>
#include <iostream>

int main(int ac, char **av)
{
    ArgumentsParser args(ac - 1, av + 1);

    args.prossessArguments();
    return 0;
}
