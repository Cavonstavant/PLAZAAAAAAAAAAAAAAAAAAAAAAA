/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Kitchen
*/

/// \file src/Core/Kitchen/Kitchen.hpp

#ifndef PLAZZA_KITCHEN_HPP
#define PLAZZA_KITCHEN_HPP

#include "Pizza.hpp"
#include "MessageQueue.hpp"
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace plazza {

    /// \brief Enumeration for the different ingredients.
    enum Ingredients {
        Tomato = 0,
        Gruyere,
        Ham,
        Mushrooms,
        Steak,
        Eggplant,
        GoatCheese,
        ChiefLove,
        Doe,
        IngredientNumber = 9
    };

    /// \brief The class used to manage all the cooks and the orders.
    class Kitchen {
        public:
            /// \brief Creating a Kitchen without specifying the number of cooks should not be possible
            Kitchen() = delete;

            /// \brief Creating a Kitchen with a specified number of cooks
            explicit Kitchen(unsigned long nbCooks, unsigned long refillTime) : _nbCooks(nbCooks), _refillTime(refillTime), _stopKitchen(false), _fridge(IngredientNumber){};

            /// \brief Destructor
            ~Kitchen() = default;

            /// \brief Starts the kitchen and init all the cooks
            /// \warning The number of cooks must be specified before starting the kitchen
            void start();

            /// \brief Stops the kitchen and joins all the cooks
            void stop();

            /// \brief Adds an order to the kitchen
            void enqueueJob(std::function<void()> &job);

        private:
            /// \brief Function getting the command and give it in the job queue
            static void _receptCook(Kitchen *obj);

            /// \brief Main function instancied in each thread
            static void _Cook(Kitchen *obj);

            /// \brief Init the fridge at the Kitchen Creation
            static void _initFridge(Kitchen &obj);

            /// \brief fill the ingredients of the fridge 1 x timeToFill
            /// \param timeToFill number of time to fill the fridge
            static void _fillFridge(const std::size_t &timeToFill, Kitchen &obj);

            /// \brief check every timeToWait to fill the fridge
            static void _waitToFillFridge(const std::size_t &timeToWait, Kitchen &obj);

            /// \brief The kitchen brigade regrouping all the cooks
            std::vector<std::thread> _brigade;

            /// \brief The mutex used to protect the kitchen ingredients
            std::mutex _mutex;

            /// \brief The condition variable used to notify the cooks that there is an order
            std::condition_variable order_condition;

            MessageQueue _commandQueue;

            /// \brief The queue of orders coming from the reception
            std::queue<std::function<void()>> _orders;

            /// \brief The number of cooks in the kitchen
            unsigned long _nbCooks;

            /// \brief The time to wait before fill the fridge
            unsigned long _refillTime;

            /// \brief Store the oldTime to fill
            unsigned long _oldTime;

            /// \brief The flag used to stop the kitchen
            bool _stopKitchen;

            /// \brief The kitchen fridge, containing all of the ingredients
            std::vector<Ingredient> _fridge;
    };

}// namespace plazza

#endif//PLAZZA_KITCHEN_HPP
