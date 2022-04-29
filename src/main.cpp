/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** main
*/

#include <string>
#include "Parser/ArgumentsParser/ArgumentsParser.hpp"

int main(int ac, char **av)
{
    ArgumentsParser args (av + 1);

    args.prossessArguments();
    return 0;
}