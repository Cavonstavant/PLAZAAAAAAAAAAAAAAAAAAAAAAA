/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** InputParser_test
*/

#include "InputParser.hpp"
#include <criterion/criterion.h>

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

Test(InputParser, test_InputParser5)
{
    plazza::InputParser p;

    p.setCommand("reginat S x25");
    p.processArguments();
    cr_assert_eq(p.getPizza().size(), 0);
}

Test(InputParser, test_InputParser6)
{
    plazza::InputParser p;

    p.setCommand("regina XS x2");
    p.processArguments();
    cr_assert_eq(p.getPizza().size(), 0);
}

Test(InputParser, test_InputParser7)
{
    plazza::InputParser p;

    p.setCommand("regina S x0");
    p.processArguments();
    cr_assert_eq(p.getPizza().size(), 0);
}

Test(InputParser, test_InputParser8)
{
    plazza::InputParser p;

    p.setCommand("regina S x1; americana XL x15           ;      ;     ;;;     fantasia XXL x254");
    p.processArguments();
    cr_assert_eq(p.getPizza().size(), 3);
}

Test(InputParser, test_InputParser9)
{
    plazza::InputParser p;

    p.setCommand("regina S x1; americana XL x15                   fantasia XXL x2486");
    p.processArguments();
    cr_assert_eq(p.getPizza().size(), 1);
}

Test(InputParser, test_InputParser10)
{
    plazza::InputParser p;

    p.setCommand("regina S x1; americana XL x15          ;   ;   ;; ; ;;;;;         fantasia XXL x2486");
    p.processArguments();
    cr_assert_eq(p.getPizza().size(), 3);
}

Test(InputParser, test_InputParser11)
{
    plazza::InputParser p;

    p.setCommand("regina S x1; americana M x58 ; margarita L x52; fantasia XL x1 ; fantasia XXL x123456");
    p.processArguments();
    cr_assert_eq(p.getPizza().size(), 5);
}

Test(InputParser, test_InputParser12)
{
    plazza::InputParser p;

    p.setCommand("regina S; americana M x5");
    p.processArguments();
    cr_assert_eq(p.getPizza().size(), 1);
}