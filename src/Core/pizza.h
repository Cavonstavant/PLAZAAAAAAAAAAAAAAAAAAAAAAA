/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** pizza
*/

#ifndef PIZZA_H_
    #define PIZZA_H_

    #include <string>

typedef pizzaSize_e pizzaSize_t;
typedef pizza_s pizza_t;

enum pizzaSize_e {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16,
};

struct pizza_s {
    std::string name;
    enum pizzaSize_e size;
    std::size_t number;
};

#endif /* !PIZZA_H_ */