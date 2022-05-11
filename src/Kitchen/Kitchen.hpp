/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Kitchen
*/

/// \file src/Kitchen/Kitchen.hpp

#ifndef PLAZZA_KITCHEN_HPP
#define PLAZZA_KITCHEN_HPP

#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>

namespace plazza {

/// \brief The class used to manage all the cooks and the orders.
class Kitchen {
    public:
        /// \brief Creating a Kitchen without specifying the number of cooks should not be possible
        Kitchen() = delete;

        /// \brief Creating a Kitchen with a specified number of cooks
        explicit Kitchen(unsigned long nbCooks) : _brigade(nbCooks), _stopKitchen(false) {};

        /// \brief Destructor
        ~Kitchen() = default;

        /// \brief Starts the kitchen and init all the cooks
        /// \warning The number of cooks must be specified before starting the kitchen
        void start();

        /// \brief Stops the kitchen and joins all the cooks
        void stop();

        /// \brief Adds an order to the kitchen
        void enqueueJob(std::function<void()>& job);

    private:
        void _Cook();

        /// \brief The kitchen brigade regrouping all the cooks
        std::vector<std::thread> _brigade;

        /// \brief The mutex used to protect the kitchen ingredients
        std::mutex _mutex;

        /// \brief The condition variable used to notify the cooks that there is an order
        std::condition_variable order_condition;

        /// \brief The queue of orders comming from the reception
        std::queue<std::function<void()>> _orders;

        /// \brief The number of cooks in the kitchen
        unsigned long _nbCooks;

        /// \brief The flag used to stop the kitchen
        bool _stopKitchen;
};

}

#endif//PLAZZA_KITCHEN_HPP
