/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** Logger_test
*/

#include "PizzaLogger.hpp"
#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <criterion/redirect.h>

using namespace plazza;

Test(pizza_logger, log_pizza_order_received, .init = cr_redirect_stdout)
{
    PizzaLogger::logPizza("pizza", PizzaLogger::ACTION_ORDER_RECIEVED);
    cr_assert_stdout_eq_str("pizza\t|\t ORDER RECIEVED\n");
}

Test(pizza_logger, log_pizza_cooking_started, .init = cr_redirect_stdout)
{
    PizzaLogger::logPizza("pizza", PizzaLogger::ACTION_COOKING_STARTED);
    cr_assert_stdout_eq_str("pizza\t|\t COOKING STARTED\n");
}

Test(pizza_logger, log_pizza_cooking_finished, .init = cr_redirect_stdout)
{
    PizzaLogger::logPizza("pizza", PizzaLogger::ACTION_COOKING_FINISHED);
    cr_assert_stdout_eq_str("pizza\t|\t COOKING FINISHED\n");
}
