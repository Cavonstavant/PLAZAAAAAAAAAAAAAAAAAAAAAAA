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
    ArgumentsParser args(av + 1);

    args.prossessArguments();
    return 0;
}
