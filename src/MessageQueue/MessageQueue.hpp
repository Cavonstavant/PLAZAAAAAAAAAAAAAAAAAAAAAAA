/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** MessageQueue
*/

/// \file src/MessageQueue/MessageQueue.hpp

#ifndef MESSAGEQUEUE_HPP
#define MESSAGEQUEUE_HPP

#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string>

#define MAX_MESSAGE_SIZE 256

/// \brief Wrapper class around the POSIX message queues.
/// \note This class aims to provide a custom interface to manipulate POSIX message queues by simply enqueue and dequeue messages with send_message and receive_message.
class MessageQueue {
public:
    /// \brief Default Constructor, no queue is created when called.
    MessageQueue() = default;

    /// \brief Destructor, the queue is destroyed / emptied when called.
    ~MessageQueue();

    /// \brief Creating a new queue from a already existing queue shall not be possible.
    MessageQueue &operator=(const MessageQueue &) = delete;

    /// \brief Creating a new queue from a already existing queue shall not be possible.
    MessageQueue(const MessageQueue &) = delete;

    /// \brief C++ wrapper around C ftok().
    void openQueue(const std::string &pathname);

    /// \brief Get the current message queue pathfile.
    /// \warning Using thing method prior to the creation of a key results in a <b>Undefined Behavior</b>.
    [[nodiscard]] inline std::string getPath() const
    {
        return _pathname;
    };

    /// \brief Sends a message to the queue.
    /// \note This method is a C++ wrapper around mq_send().
    /// \warning Using thing method prior to opening a queue results in a <b>Undefined Behavior</b>.
    /// \param message The message to be sent.
    /// \param message_type the type of the message.
    void sendMessage(const std::string &message_text);

    /// \brief Receives a message from the queue.
    /// \note This method is a C++ wrapper around mq_receive().
    /// \warning Using thing method prior to opening a queue results in a <b>Undefined Behavior</b>.
    /// \param message_type the type of the message.
    [[nodiscard]] std::string receiveMessage();

    /// \brief Clear the queue.
    /// \warning Using thing method prior to opening a queue results in a <b>Undefined Behavior</b>.
    void clear();

private:
    /// \brief Message queue fd.
    mqd_t _queue_fd{};

    /// \brief The pathfile of the queue.
    std::string _pathname{};
};

#endif /* MESSAGEQUEUE_HPP */
