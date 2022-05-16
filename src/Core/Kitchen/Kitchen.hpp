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
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace plazza {

    /// \brief Enumeration for the different ingredients.
    enum Ingredients {
        Tomato,
        Gruyere,
        Ham,
        Mushrooms,
        Steak,
        Eggplant,
        GoatCheese,
        ChiefLove,
        IngredientNumber
    };

    /// \brief The class used to manage all the cooks and the orders.
    class Kitchen {
        public:
            /// \brief Creating a Kitchen without specifying the number of cooks should not be possible
            Kitchen() = delete;

            /// \brief Creating a Kitchen with a specified number of cooks
            explicit Kitchen(unsigned long nbCooks) : _nbCooks(nbCooks), _stopKitchen(false), _fridge(8){};

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
            /// \brief fill the ingredients of the fridge 1 x timeToFill
            /// \param timeToFill number of time to fill the fridge 
            void _fillFridge(const std::size_t &timeToFill);

            /// \brief Main function instancied in each thread
            static void _Cook(Kitchen *obj);

            /// \brief The kitchen fridge, containing all of the ingredients
            std::vector<Ingredient> _fridge;

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

}// namespace plazza

#endif//PLAZZA_KITCHEN_HPP
