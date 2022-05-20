/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Kitchen
*/

/// \file src/Core/Kitchen/Kitchen.hpp

#ifndef PLAZZA_KITCHEN_HPP
#define PLAZZA_KITCHEN_HPP

#include "MessageQueue.hpp"
#include "Pizza.hpp"
#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace plazza {

    /// \brief Enumeration for the different ingredients.
    enum Ingredients {
        Tomato = 1,
        Gruyere,
        Ham,
        Mushrooms,
        Steak,
        Eggplant,
        GoatCheese,
        Doe,
        IngredientNumber
    };

    /// \brief The class used to manage all the cooks and the orders.
    class Kitchen {
        public:
            /// \brief Creating a Kitchen without specifying the number of cooks should not be possible
            Kitchen() = delete;

            /// \brief Creating a Kitchen with a specified number of cooks
            explicit Kitchen(unsigned long nbCooks, unsigned long refillTime, unsigned long cookingTime) : _nbCooks(nbCooks), _availCooks(nbCooks), _refillTime(refillTime), _cookingTime(cookingTime), _stopKitchen(false) 
            {
                _fridge.resize(IngredientNumber);
            };

            /// \brief Destructor
            ~Kitchen() = default;

            /// \brief Starts the kitchen and init all the cooks
            /// \warning The number of cooks must be specified before starting the kitchen
            void start();

            /// \brief Stops the kitchen and joins all the cooks
            void stop();

            /// \brief Adds an order to the kitchen
            void enqueueJob(Pizza &pizza);

            /// \brief used to check if all the cooks have finished cooking
            /// or still have order to process
            bool isBusy();

            /// \brief MessageQueue recepting the command from the reception
            std::shared_ptr<MessageQueue> commandQueue;

            /// \brief get the Pizza Type from the Command
            /// \param fullCommand the String received in the Queue
            /// \return the pizza type
            static PizzaType getTypeFromFullCommand(const std::string &fullCommand);

            /// \brief get the number of the pizza from the Command
            /// \param fullCommand the String received in the Queue
            /// \return the quantity of the Pizza
            static int getQuantityFromFullCommand(const std::string &FullCommand);

            /// \brief get the necessary ingredients from the pizza type
            /// \param toCook the Pizza to be filled with ingredients
            /// \param type the type of the Pizza
            static void getIngredientsFromPizzaType(Pizza &toCook, PizzaType type);
            /// \brief Unpack std::string in Pizza.
            /// \param std::string to be unpack.
            /// \return Pizza unpacked.
            static Pizza unpack(const std::string &order);

        private:
            /// \brief Check if the command ask for available cook ("avail_cooks ?")
            /// \param std::string & The command to be check
            /// \return bool True if it is the correct command, false otherwise
            static bool _isAvailableCook(std::string &);

            /// \brief Main function for the Blocking thread on the message queue, getting the command and give it in the job queue
            static void _receptCook(Kitchen *obj);

            /// \brief Main function instancied in each thread
            static void _Cook(Kitchen *obj);

            /// \brief Init the fridge at the Kitchen Creation
            static void _initFridge(Kitchen *obj);

            /// \brief fill the ingredients of the fridge 1 x timeToFill
            /// \param timeToFill number of time to fill the fridge
            static void _fillFridge(const std::size_t &timeToFill, Kitchen *obj);

            /// \brief check every timeToWait to fill the fridge
            static void _waitToFillFridge(const std::size_t &timeToWait, Kitchen *obj);

            /// \brief The kitchen brigade regrouping all the cooks
            std::vector<std::thread> _brigade;

            /// \brief The mutex used to protect the kitchen ingredients
            std::mutex _mutex;

            /// \brief The mutex used to protect the refill of the kitchen ingredients
            std::mutex _fridgeMutex;

            /// \brief The condition variable used to notify the cooks that there is an order
            std::condition_variable order_condition;

            /// \brief The list of pizzas waiting to be cooked by the cooks
            std::queue<Pizza> _orders;

            /// \brief The number of cooks in the kitchen
            unsigned long _nbCooks;

            /// \brief The number of available cooks
            unsigned long _availCooks;

            /// \brief The time to wait before fill the fridge
            unsigned long _refillTime;

            /// \brief The multiplier for the cooking Time
            float _cookingTime;

            /// \brief Store the old time to refill the fridge
            unsigned long _oldTime;

            /// \brief The flag used to stop the kitchen
            bool _stopKitchen;

            /// \brief The kitchen fridge, containing all of the ingredients
            std::vector<Ingredient> _fridge;
    };

}// namespace plazza

#endif//PLAZZA_KITCHEN_HPP
