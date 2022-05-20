/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Pizza_test
*/

#include <criterion/criterion.h>
#include "Pizza.hpp"

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

Test(Ingredient, test12)
{
    std::vector<plazza::Ingredient> i;
    std::vector<plazza::Ingredient> j;
    plazza::Ingredient k;

    k.name = "doe";
    k.number = 5;
    i.push_back(k);
    k.number = 1;
    j.push_back(k);
    k.name = "tomato";
    k.number = 5;
    i.push_back(k);
    k.number = 2;
    j.push_back(k);
    i = i - j;
    cr_assert_eq(i.back().number, 3);
}

Test(Ingredient, test13)
{
    std::vector<plazza::Ingredient> i;
    std::vector<plazza::Ingredient> j;
    plazza::Ingredient k;

    k.name = "doe";
    k.number = 5;
    i.push_back(k);
    k.number = 1;
    j.push_back(k);
    k.name = "tomato";
    k.number = 5;
    i.push_back(k);
    k.number = 2;
    j.push_back(k);
    i -= j;
    cr_assert_eq(i.front().number, 4);
}

Test(Ingredient, test14)
{
    std::vector<plazza::Ingredient> i;
    std::vector<plazza::Ingredient> j;
    plazza::Ingredient k;

    k.name = "doe";
    k.number = 5;
    i.push_back(k);
    k.number = 1;
    j.push_back(k);
    k.name = "tomato";
    k.number = 5;
    i.push_back(k);
    k.number = 8;
    j.push_back(k);
    cr_assert_throw(i -= j, std::exception);
}

Test(Ingredient, test15)
{
    std::vector<plazza::Ingredient> i;
    std::vector<plazza::Ingredient> j;
    plazza::Ingredient k;

    k.name = "doe";
    k.number = 5;
    i.push_back(k);
    k.number = 1;
    j.push_back(k);
    k.name = "tomato";
    k.number = 5;
    i.push_back(k);
    k.number = 8;
    j.push_back(k);
    cr_assert_throw(i = i - j, std::exception);
}

Test(Ingredient, test16)
{
    std::vector<plazza::Ingredient> i;
    std::vector<plazza::Ingredient> j;
    plazza::Ingredient k;
    plazza::Pizza p;

    k.name = "doe";
    k.number = 5;
    i.push_back(k);
    k.number = 1;
    j.push_back(k);
    k.name = "tomato";
    k.number = 5;
    i.push_back(k);
    k.number = 2;
    j.push_back(k);
    p.ingredients = j;
    i -= p;
    cr_assert_eq(i.front().number, 4);
}

Test(Ingredient, test17)
{
    std::vector<plazza::Ingredient> i;
    std::vector<plazza::Ingredient> j;
    plazza::Ingredient k;
    plazza::Pizza p;

    k.name = "doe";
    k.number = 5;
    i.push_back(k);
    k.number = 1;
    j.push_back(k);
    k.name = "tomato";
    k.number = 5;
    i.push_back(k);
    k.number = 2;
    j.push_back(k);
    p.ingredients = j;
    i = i - p;
    cr_assert_eq(i.front().number, 4);
}

Test(Ingredient, test18)
{
    std::vector<plazza::Ingredient> i;
    std::vector<plazza::Ingredient> j;
    plazza::Ingredient k;
    plazza::Pizza p;

    k.name = "doe";
    k.number = 5;
    i.push_back(k);
    k.number = 1;
    j.push_back(k);
    k.name = "tomato";
    k.number = 5;
    i.push_back(k);
    k.number = 8;
    j.push_back(k);
    p.ingredients = j;
    cr_assert_throw(i -= p, std::exception);
}

Test(Ingredient, test19)
{
    std::vector<plazza::Ingredient> i;
    std::vector<plazza::Ingredient> j;
    plazza::Ingredient k;
    plazza::Pizza p;

    k.name = "doe";
    k.number = 5;
    i.push_back(k);
    k.number = 1;
    j.push_back(k);
    k.name = "tomato";
    k.number = 5;
    i.push_back(k);
    k.number = 8;
    j.push_back(k);
    p.ingredients = j;
    cr_assert_throw(i = i - p, std::exception);
<<<<<<< HEAD
}
=======
}
>>>>>>> c85deb1 ([+] fix some conflict on merge from main)
