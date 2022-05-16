/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** main
*/

#include "ArgumentsParser.hpp"
#include "Exception.hpp"
#include "MessageQueue/MessageQueue.hpp"
#include "Plazza.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    plazza::ArgumentsParser args(ac - 1, av + 1);

    try {
        args.processArguments();
    } catch (const PlazzaException &exc) {
        std::cerr << exc.what() << std::endl;
        return 84;
    }
    plazza::Reception reception(args.getCookingTime(), args.getCookNumber(), args.getRefillTime());

    reception.run();

    return 0;
}
