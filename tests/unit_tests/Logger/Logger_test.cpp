/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** Logger_test
*/

#include "Logger.hpp"
#include "PizzaLogger.hpp"
#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <criterion/redirect.h>

using namespace plazza;

Test(pizza_logger, log_pizza_order_received, .init = cr_redirect_stdout)
{
    PizzaLogger::logPizza("pizza", PizzaLogger::ACTION_ORDER_RECIEVED);
    cr_assert_stdout_eq_str("pizza\tStatus: ORDER RECIEVED\n");
}

Test(pizza_logger, log_pizza_cooking_started, .init = cr_redirect_stdout)
{
    PizzaLogger::logPizza("pizza", PizzaLogger::ACTION_COOKING_STARTED);
    cr_assert_stdout_eq_str("pizza\tStatus: COOKING STARTED\n");
}

Test(pizza_logger, log_pizza_cooking_finished, .init = cr_redirect_stdout)
{
    PizzaLogger::logPizza("pizza", PizzaLogger::ACTION_COOKING_FINISHED);
    cr_assert_stdout_eq_str("pizza\tStatus: COOKING FINISHED\n");
}

Test(logger, logger_log_none)
{
    cr_assert_eq(Logger::NONE(), Logger::SEVERITY_NONE);
}

Test(logger, logger_log_low)
{
    cr_assert_eq(Logger::LOW(), Logger::SEVERITY_LOW);
}

Test(logger, logger_log_medium)
{
    cr_assert_eq(Logger::MEDIUM(), Logger::SEVERITY_MEDIUM);
}

Test(logger, logger_log_high)
{
    cr_assert_eq(Logger::HIGH(), Logger::SEVERITY_HIGH);
}

Test(logger, logger_log_critical)
{
    cr_assert_eq(Logger::CRITICAL(), Logger::SEVERITY_CRITICAL);
}

Test(logger, logger_log_info)
{
    cr_assert_eq(Logger::INFO(), Logger::SEVERITY_INFO);
}
