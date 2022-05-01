/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** MessageQueue
*/

/// \file src/MessageQueue/MessageQueue.hpp

#ifndef MESSAGEQUEUE_HPP
#define MESSAGEQUEUE_HPP

extern "C" {
    #include <sys/ipc.h>
    #include <sys/msg.h>
}
#include <string>

#define MAX_MESSAGE_SIZE 256

/// \brief Wrapper class around the XSI message queues.
/// \note This class aims to provide a custom interface to manipulate XSI message queues by simply enqueue and dequeue messages with send_message and receive_message.
class MessageQueue {
    public:
        /// \brief Default Constructor, no queue is created when called.
        MessageQueue() = default;

        /// \brief Destructor, the queue is destroyed / emptied when called.
        ~MessageQueue() = default;

        /// \brief Creating a new queue from a already existing queue shall not be possible.
        MessageQueue &operator=(const MessageQueue &) = delete;

        /// \brief Creating a new queue from a already existing queue shall not be possible.
        MessageQueue(const MessageQueue &) = delete;

        /// \brief Retrieve the current text representation of the last message received.
        /// \warning Calling this method without setting up the queue, receiving a message or sending first will result in a <b>Undefined Behavior</b>.
        [[nodiscard]] inline std::string getMessage() const { return _text; };

        /// \brief Get the current message queue key.
        [[nodiscard]] inline key_t getKey() const { return _key; };

        /// \brief Set the message queue key.
        /// \note In order to create a new key, please use the MessageQueue::generateKey static method.
        inline void setKey(key_t key) { _key = key; };

        /// \brief C++ wrapper around C ftok().
        /// \note This methods sets internally the key to be used.
        /// \note proj_id is defaulted to 69.
        void generateKey(const std::string& pathname, int proj_id = 69);

        /// \brief Get the current message queue pathfile.
        /// \warning Using thing method prior to the creation of a key results in a <b>Undefined Behavior</b>.
        [[nodiscard]] inline std::string getPath() const { return _pathname; };

        /// \brief Get the current message queue id.
        /// \warning Using thing method prior to the creation of a key results in a <b>Undefined Behavior</b>.
        /// \return The id returned by msgget().
        [[nodiscard]] inline int getId() const { return _id; };

        /// \brief Get the current message queue id.
        /// \warning Using thing method prior to the creation of a key results in a <b>Undefined Behavior</b>.
        inline void setId(int id) { _id = id; };

        /// \brief Sends a message to the queue.
        /// \note This method is a C++ wrapper around msgsnd().
        /// \warning Using thing method prior to the creation of a key results in a <b>Undefined Behavior</b>.
        /// \param message The message to be sent.
        /// \param message_type the type of the message.
        void sendMessage(const std::string& message_text, long message_type);

        /// \brief Receives a message from the queue.
        /// \note This method is a C++ wrapper around msgrcv().
        /// \warning Using thing method prior to the creation of a key results in a <b>Undefined Behavior</b>.
        /// \param message_type the type of the message.
         [[nodiscard]] std::string receiveMessage(long message_type);

        /// \brief Clear the queue.
        /// \warning Using thing method prior to the creation of a key results in a <b>Undefined Behavior</b>.
        void clear();
    private:

        /// \brief Inner representation of a message used by msgsnd() and msgrcv().
        struct message {
            /// \brief The message type.
            long type;
            /// \brief The message text.
            char text[MAX_MESSAGE_SIZE];
        };

        /// \brief message instance to be used with msgsnd() and msgrcv().
        struct message *_msg = nullptr;

        /// \brief The text representation of the last message received.
        std::string _text;

        /// \brief The type associated with the last message received.
        long _type{};

        /// \brief The queue id returned by msgget().
        int _id{};

        /// \brief XSI key used to represent the queue.
        key_t _key{};

        /// \brief The pathfile of the queue.
        std::string _pathname;
};

#endif /* MESSAGEQUEUE_HPP */
