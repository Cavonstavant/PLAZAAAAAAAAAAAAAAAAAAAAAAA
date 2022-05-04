/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** MessageQueue
*/

#include "MessageQueue.hpp"
#include "Exception.hpp"
#include "Logger.hpp"
#include <cstring>
#include <cerrno>
#include <string>

void MessageQueue::generateKey(const std::string &pathname, int proj_id)
{
    key_t key = ftok(pathname.c_str(), proj_id);

    if (key == -1)
        throw MessageQueueEX(std::string("Could not generate IPC key with ftok: ") + std::strerror(errno), Logger::CRITICAL);
    this->_key = key;
}
void MessageQueue::sendMessage(const std::string &message_text, long message_type)
{
    int message_id;

    if (message_text.length() >= MAX_MESSAGE_SIZE)
        throw MessageTooLongEX("Message is too long", Logger::MEDIUM);
    message_id = msgget(this->_key, 0666 | IPC_CREAT);
    if (message_id == -1) {
        exit(84);
    }
    _msg = new MessageQueue::message{.type = message_type};
    std::strcpy(_msg->text, message_text.c_str());
    if (msgsnd(message_id, (void *) &_msg, sizeof(_msg->text), 0) == -1)
        throw MessageQueueEX(std::string("Could not send message: ") + std::strerror(errno), Logger::CRITICAL);
    delete _msg;
}

std::string MessageQueue::receiveMessage(long message_type)
{
    int message_id = msgget(this->_key, 0666 | IPC_CREAT);
    ssize_t message_size;
    MessageQueue::message *msg = new MessageQueue::message;

    if (message_id == -1)
        throw MessageQueueEX(std::string("Could not receive message: ") + std::strerror(errno), Logger::CRITICAL);
    message_size = msgrcv(message_id, (void *) &msg, sizeof(msg->text), message_type, 0);
    if (message_size < 0)
        throw MessageQueueEX(std::string("Could not receive message: ") + std::strerror(errno), Logger::CRITICAL);
    return msg->text;
}

void MessageQueue::clear()
{
    msgctl(this->_key, IPC_RMID, nullptr);
}
