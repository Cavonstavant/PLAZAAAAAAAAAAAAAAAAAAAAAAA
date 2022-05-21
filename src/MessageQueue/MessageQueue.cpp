/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** MessageQueue
*/

#include "MessageQueue.hpp"
#include "Exception.hpp"
#include "Logger.hpp"
#include <cerrno>
#include <cstring>
#include <string>

MessageQueue::~MessageQueue()
{
    mq_close(this->_queue_fd);
    clear();
}

void MessageQueue::openQueue(const std::string &pathname)
{
    struct mq_attr attr;

    this->_queue_fd = mq_open(pathname.c_str(), O_RDWR | O_CREAT, 0666, NULL);
    mq_getattr(this->_queue_fd, &attr);
    attr.mq_msgsize = MAX_MESSAGE_SIZE + 1;
    mq_setattr(this->_queue_fd, &attr, NULL);
    if (this->_queue_fd == -1)
        throw MessageQueueEx(std::string("Failed to open queue: ") + std::strerror(errno), Logger::CRITICAL);
    this->_pathname = pathname;
}
void MessageQueue::sendMessage(const std::string &message_text) const
{
    int mq_send_return = mq_send(this->_queue_fd, message_text.c_str(), message_text.length(), 0);

    if (mq_send_return == -1)
        throw MessageQueueEx(std::string("Failed to send message: ") + std::strerror(errno), Logger::CRITICAL);
}

std::string MessageQueue::receiveMessage() const
{
    ssize_t mq_receive_return = 0;
    char message_buffer[MAX_MESSAGE_SIZE] = {0};
    struct mq_attr attr;

    mq_getattr(this->_queue_fd, &attr);
    mq_receive_return = mq_receive(this->_queue_fd, message_buffer, attr.mq_msgsize, 0);
    if (mq_receive_return == -1)
        throw MessageQueueEx(std::string("Failed to receive message: ") + std::strerror(errno), Logger::CRITICAL);
    return std::string(message_buffer);
}

void MessageQueue::clear()
{
    if (mq_unlink(this->_pathname.c_str()) == -1)
        throw MessageQueueEx(std::string("Failed to clear queue: ") + std::strerror(errno), Logger::CRITICAL);
}

std::string &operator<<(std::string &i, const MessageQueue &queue)
{
    i = queue.receiveMessage();
    return i;
}

MessageQueue &operator>>(MessageQueue &queue, std::string &i)
{
    queue.sendMessage(i);
    return queue;
}
