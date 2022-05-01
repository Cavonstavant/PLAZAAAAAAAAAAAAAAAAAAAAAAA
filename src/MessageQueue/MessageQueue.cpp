/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** MessageQueue
*/

#include "Exception.hpp"
#include "Logger.hpp"
#include "MessageQueue.hpp"
#include <string>
#include <cstring>

void MessageQueue::generateKey(const std::string& pathname, int proj_id)
{
    key_t key = ftok(pathname.c_str(), proj_id);

    if (key == -1) {
        exit(84);
    }
    this->_key = key;
}
void MessageQueue::sendMessage(const std::string& message_text, long message_type)
{
    int message_id;

    if (message_text.length() >= MAX_MESSAGE_SIZE)
        throw PlazzaEX("Message is too long", Logger::MEDIUM);
    message_id = msgget(this->_key, 0666 | IPC_CREAT);
    if (message_id == -1) {
        exit(84);
    }
    _msg = new MessageQueue::message {.type = message_type};
    std::strcpy(_msg->text, message_text.c_str());
    if (msgsnd(message_id, (void*) &_msg, sizeof(_msg->text), 0) == -1) {
        exit(84);
    }
    delete _msg;
}

std::string MessageQueue::receiveMessage(long message_type)
{
    int message_id = msgget(this->_key, 0666 | IPC_CREAT);
    MessageQueue::message *msg = nullptr;

    if (message_id == -1) {
        exit(84);
    }
    msgrcv(message_id, (void*) &msg, sizeof(msg->text), message_type, 0);
    return msg->text;
}

void MessageQueue::clear()
{
    msgctl(this->_key, IPC_RMID, nullptr);
}