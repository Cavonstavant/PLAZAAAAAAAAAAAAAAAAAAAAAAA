/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** Logger_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "MessageQueue.hpp"

#define private public

#include "Kitchen.hpp"

using namespace plazza;

Test(kitchen, kitchen_create_kitchen)
{
    Kitchen kitchen(10, 2, 2);

    cr_assert_eq(kitchen._nbCooks, 10);
    cr_assert_eq(kitchen._refillTime, 2);
    cr_assert_eq(kitchen._cookingTime, 2);
    cr_assert_eq(kitchen._fridge.size(), IngredientNumber);
    cr_assert_eq(kitchen._needToBeKilled, false);
}

Test(kitchen, kitchen_instaciation)
{
    Kitchen kitchen(10, 2, 2);

    kitchen.commandQueue = std::make_shared<MessageQueue>();
    kitchen.commandQueue.get()->openQueue("/TestMessageQueue");
    cr_assert_str_eq(kitchen.commandQueue.get()->getQueueName().c_str(), "/TestMessageQueue");
}
