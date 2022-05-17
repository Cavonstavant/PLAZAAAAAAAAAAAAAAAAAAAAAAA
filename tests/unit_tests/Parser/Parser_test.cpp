/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Parser_test
*/

#include <criterion/criterion.h>
#include "InputParser.hpp"

Test(InputParser, test_InputParser1)
{
    plazza::InputParser p;

    cr_assert_eq(1, 1);
}

Test(InputParser, test_InputParser2)
{
    plazza::InputParser p;
    std::vector<std::string> v;

    p.setCommand("regina L x1");
    p.setCommandSeparator(' ');
    p.processArguments();
    v = p.getArguments();
    cr_assert_eq(v.size(), 4);
}

Test(InputParser, test_InputParser3)
{
    plazza::InputParser p;

    p.setCommand("regina XL x10");
    p.processArguments();
    cr_assert_str_eq(p.getCommand().c_str(), "regina XL x10");
}

Test(InputParser, test_InputParser4)
{
    plazza::InputParser p;
    std::vector<plazza::Pizza> v;

    p.setCommand("americana S x289");
    p.processArguments();
    v = p.getPizza();
    cr_assert_eq(v.size(), 1);
}