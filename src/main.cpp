/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** main
*/

#include "Parser/ArgumentsParser/ArgumentsParser.hpp"
#include "Core/Plazza.hpp"

int main(int ac, char **av)
{
    ArgumentsParser args(ac - 1, av + 1);

    try {
        args.prossessArguments();
    } catch (...) {
        return 84;
    }
    Plazza::Core (args.getCookingTime(), args.getCookNumber(), args.getRefillTime());

    return 0;
}
