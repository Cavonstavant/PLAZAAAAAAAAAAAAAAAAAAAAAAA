/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** messageQueue_test
*/

#include <criterion/criterion.h>
#include <iostream>
#include "MessageQueue/MessageQueue.hpp"

Test(MessageQueue, test_messageQueue)
{
    MessageQueue mq;
    std::string received;
    mq.openQueue("/PlazzaTestMq");
    mq.sendMessage("Hello World");
    cr_assert_str_eq(received.c_str(), "Hello World");
}
