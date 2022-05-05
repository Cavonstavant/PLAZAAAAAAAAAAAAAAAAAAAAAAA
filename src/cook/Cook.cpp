/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Cook
*/

#include "Cook.hpp"

plazza::Cook::Cook()
{
    _IHaveACommand = false;
}

void plazza::Cook::cookTakeThisCommand(const std::string command)
{
    _IHaveToMakeThisPizza = command;
    _IHaveACommand = true;
    _setIngredientsListFromCommand();
}