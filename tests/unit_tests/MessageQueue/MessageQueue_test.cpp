/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** messageQueue_test
*/

#include "MessageQueue.hpp"
#include <criterion/criterion.h>
#include <fcntl.h>
#include <iostream>
#include <sys/stat.h>

Test(MessageQueue, test_messageQueue_basic)
{
    MessageQueue mq;
    std::string received;
    mq.openQueue("/PlazzaTestMq");
    mq.sendMessage("Hello World");
    received = mq.receiveMessage();
    cr_assert_str_eq(received.c_str(), "Hello World");
}

Test(MessageQueue, test_messageQueue_operators)
{
    MessageQueue mq;
    std::string message = "Hello World";
    std::string received;

    mq.openQueue("/PlazzaTestMq");
    mq >> message;
    received << mq;
    cr_assert_str_eq(received.c_str(), message.c_str());
}
