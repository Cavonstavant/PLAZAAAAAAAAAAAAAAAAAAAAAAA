/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** Logger_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#define private public

#include "Cook.hpp"

using namespace plazza;

Test(cook, cook_instanciation)
{
    Cook cook;
    cr_assert_eq(cook._multiplier, 1);
}

Test(cook, cook_unpack)
{
    Pizza pizza;
    std::string test;
    Cook cook;

    pizza.type = Regina;
    pizza.size = S;

    test = cook.pack(pizza);
    cr_assert_str_eq(test.c_str(), "regina of size S");
    pizza.type = Americana;
    test = cook.pack(pizza);
    cr_assert_str_eq(test.c_str(), "americana of size S");
    pizza.type = Fantasia;
    test = cook.pack(pizza);
    cr_assert_str_eq(test.c_str(), "fantasia of size S");
    pizza.type = Margarita;
    test = cook.pack(pizza);
    cr_assert_str_eq(test.c_str(), "margarita of size S");
    pizza.size = M;
    test = cook.pack(pizza);
    cr_assert_str_eq(test.c_str(), "margarita of size M");
    pizza.size = L;
    test = cook.pack(pizza);
    cr_assert_str_eq(test.c_str(), "margarita of size L");
    pizza.size = XL;
    test = cook.pack(pizza);
    cr_assert_str_eq(test.c_str(), "margarita of size XL");
    pizza.size = XXL;
    test = cook.pack(pizza);
    cr_assert_str_eq(test.c_str(), "margarita of size XXL");
}

Test(cook, cook_cook_pizza, .init=cr_redirect_stdout)
{
    Pizza pizza;

    pizza.type = Regina;
    pizza.size = S;

    Cook cook;
    cook.cookPizza(pizza);
    cr_assert_stdout_eq_str("regina of size S\tStatus: COOKING STARTED\nregina of size S\tStatus: COOKING FINISHED\n");
}

Test(cook, setCookingTimeMult)
{
    Cook cook;

    cook.setCookingTimeMultipiler(2);
    cr_assert_eq(cook._multiplier, 2);
}
