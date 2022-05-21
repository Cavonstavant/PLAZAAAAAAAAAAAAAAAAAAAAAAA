/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Pizza_test
*/

#include "Pizza.hpp"
#include <criterion/criterion.h>
#include <iostream>

Test(Ingredient, test01)
{
    plazza::Ingredient i = {"tomato", 5};
    plazza::Ingredient j = {"tomato", 1};

    i -= j;
    cr_assert_eq(i.number, 4);
}

Test(Ingredient, test02)
{
    plazza::Ingredient i = {"tomato", 5};
    plazza::Ingredient j = {"tomato", 1};

    i = i - j;
    cr_assert_eq(i.number, 4);
}

Test(Ingredient, test03)
{
    plazza::Ingredient i = {"tomato", 5};
    plazza::Ingredient j = {"tomato", 5};

    i = i - j;
    cr_assert_eq(i.number, 0);
}

Test(Ingredient, test04)
{
    plazza::Ingredient i = {"tomato", 5};
    std::size_t j = 2;

    i = i - j;
    cr_assert_eq(i.number, 3);
}

Test(Ingredient, test05)
{
    plazza::Ingredient i = {"tomato", 5};
    std::size_t j = 2;

    i -= j;
    cr_assert_eq(i.number, 3);
}

Test(Ingredient, test06)
{
    plazza::Ingredient i = {"tomato", 5};
    std::size_t j = 8;

    cr_assert_throw(i -= j, std::exception);
}

Test(Ingredient, test07)
{
    plazza::Ingredient i = {"tomato", 5};
    std::size_t j = 8;

    cr_assert_throw(i = i - j, std::exception);
}

Test(Ingredient, test08)
{
    plazza::Ingredient i = {"tomato", 5};
    plazza::Ingredient j = {"tomato", 8};

    cr_assert_throw(i = i - j, std::exception);
}

Test(Ingredient, test09)
{
    plazza::Ingredient i = {"tomato", 5};
    plazza::Ingredient j = {"tomato", 8};

    cr_assert_throw(i -= j, std::exception);
}

Test(Ingredient, test10)
{
    plazza::Ingredient i = {"tomato", 5};
    plazza::Ingredient j = {"doe", 2};

    cr_assert_throw(i = i - j, std::exception);
}

Test(Ingredient, test11)
{
    plazza::Ingredient i = {"tomato", 5};
    plazza::Ingredient j = {"doe", 2};

    cr_assert_throw(i -= j, std::exception);
}
