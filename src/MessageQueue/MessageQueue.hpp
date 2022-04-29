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

/// \brief Wrapper class around the XSI message queues.
/// \note This class aim to provide a custom interface to manipulate XSI message queues by simply send enqueue and dequeue messages with send_message and receive_message.
class MessageQueue {
    public:
        MessageQueue() = default;
        ~MessageQueue() = default;
        MessageQueue &operator=(const MessageQueue &) = default;
        MessageQueue(const MessageQueue &) = default;
        inline std::string getMessage() const { return _text; };
        inline void setMessage(std::string text) { _text = text; };
        inline key_t getKey() const { return _key; };
        inline void setKey(key_t key) { _key = key; };
        void create_key(std::string pathname);
        inline std::string getPath() const { return _pathname; };
        inline void setPath(std::string pathname) { _pathname = pathname; };
        inline int getId() const { return _id; };
        inline void setId(int id) { _id = id; };
        void send_message(std::string message_text, long message_type);
        std::string receive_message(long message_type);
        void clear();
    private:
        struct message {
            long type;
            char text[256];
        };
        struct message _msg;
        long _type;
        std::string _text;
        int _id;
        key_t _key;
        std::string _pathname;
};

#endif /* MESSAGEQUEUE_HPP */
