/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** PizzaLogger
*/

/// \file src/Logger/PizzaLogger.hpp

#ifndef PIZZALOGGER_HPP
#define PIZZALOGGER_HPP

#include <string>

namespace plazza {

    /// \brief Utility class to log pizzas actions during the execution of the program
    struct PizzaLogger {

            /// \brief Action representation
            enum Action {
                /// A new order is recieved
                ACTION_ORDER_RECIEVED,

                /// The order is being processed
                ACTION_COOKING_STARTED,

                /// The ordered pizza is ready
                ACTION_COOKING_FINISHED,

                /// Enum size --- Keep Last
                ACTION_ENUM_SIZE
            };

            /// \brief Deleted Constructor, this class must not be instantiated.
            PizzaLogger() = delete;

            /// \brief Default destructor
            ~PizzaLogger() = default;

            /// \brief Log an action related to a pizza order inside the standard output
            /// as well as in`log/OrdersBacklog.log`
            /// \param pizza the pizza name to log
            /// \param action the action related to to order
            static void logPizza(std::string const &pizza, Action action);

            /// \brief Static function used to encapsulate the order received action
            /// \return Action::ACTION_ORDER_RECIEVED
            static Action ORDER_RECIEVED();

            /// \brief Static function used to encapsulate the cooking started action
            /// \return Action::ACTION_COOKING_STARTED
            static Action COOKING_STARTED();

            /// \brief Static function used to encapsulate the cooking finished action
            /// \return Action::ACTION_COOKING_FINISHED
            static Action COOKING_FINISHED();
    };
}// namespace plazza


#endif /* PIZZALOGGER_HPP */
