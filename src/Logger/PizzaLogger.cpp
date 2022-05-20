/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** PizzaLogger
*/

#include "PizzaLogger.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

using namespace plazza;

static std::string getActionString(PizzaLogger::Action action)
{
    switch (action) {
    case PizzaLogger::ACTION_ORDER_RECIEVED:
        return "ORDER RECIEVED";
    case PizzaLogger::ACTION_COOKING_STARTED:
        return "COOKING STARTED";
    case PizzaLogger::ACTION_COOKING_FINISHED:
        return "COOKING FINISHED";
    default:
        return "UNKNOWN";
    }
}

void PizzaLogger::logPizza(std::string const &pizza, Action action)
{
    std::ofstream pizzaOf;
    std::stringstream ss;
    std::cout << pizza << ": " << getActionString(action) << std::endl;

    try {
        ss << pizza << ": " << getActionString(action) << std::endl;
        pizzaOf.open("OrderBacklog.log", std::ios::app);
        pizzaOf << ss.str();
        pizzaOf.close();
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}