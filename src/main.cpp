/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** main
*/

#include "Parser/ArgumentsParser/ArgumentsParser.hpp"
#include <string>

int main(int ac, char **av)
{
    ArgumentsParser args(ac - 1, av + 1);

    args.processArguments();
    return 0;
}
