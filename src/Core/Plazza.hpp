/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAA
** File description:
** Plazza
*/

/// \file src/Core/Plazza.hpp

#ifndef PLAZZA_HPP_
#define PLAZZA_HPP_

#include "InputParser.hpp"
#include "Kitchen.hpp"
#include "Pizza.hpp"
#include <cstddef>
#include <map>
#include <string>

namespace plazza {
    /// \brief Reception Class containing the main loop of the program
    class Reception {
        public:
            /// \brief Default Constructor of the Reception class DO NOT USE or it will lead to undefined comportements
            Reception() = default;
            /// \brief Construct the Reception with the necessary parameters for the method run()
            /// \param cookingTime needs to be get of an ArgumentsParser Object with getCookingTime() method
            /// \param cookNumber needs to be get of an ArgumentsParser Object with getCookNumber() method
            /// \param refillTime needs to be get of an ArgumentsParser Object with getRefillTime() method
            Reception(float cookingTime, size_t cookNumber, size_t refillTime);
            /// \brief Default Constructor of the Reception
            ~Reception() = default;
            /// \brief Pack a Pizza in std::string.
            /// \param Pizza to be pack.
            /// \return std::string packed.
            std::string pack(const Pizza &);
            /// \brief Unpack std::string in Pizza.
            /// \param std::string to be unpack.
            /// \return Pizza unpacked.
            Pizza unpack(const std::string &);
            /// \brief Main function of the program
            void run();

        private:
            /// \brief Close the Kitchens Queues and send a kill signal
            void _cleanKitchens(void);

            /// \brief Create a new Kitchen and it's associated Message Queue
            void _createNewKitchen(void);

            /// \brief Sends the `avail_slots?` command² to all the kitchens and updates `_busyCooks`
            void _updateBusyCooks(void);

            /// \brief return true or false wether there is a need to create a new kitchen
            bool _isNewKitchenNeeded(int pizzaAmt);

            int _isAvailableSlots(std::string);
            /// \brief Display all of the kitchens current status
            void _displayKitchensStatus(void);

            /// \brief Handle the receive input
            /// \return true if the input is valid, false otherwise
            bool _handleInput(const std::string &input);

            /// \brief Create a kitchen if necessary, and send the command to the child process
            void _manageOrders(const InputParser &command);

            /// \brief Sends amt of pizza to the kitchen referenced by it's id
            /// \param pizzaToCook The collection of pizza to cook
            /// \param amt The amount of pizza to send to the kitchen
            /// \param kitchenPid The kitchen subprocess pid
            void _sendPizza(std::vector<Pizza> &pizzaToCook, int amt, pid_t kitchenPid);

            /// \brief Map of the different child process, with the linked queues
            std::map<pid_t, std::shared_ptr<MessageQueue>> _kitchenMap;

            /// \brief Store the cookingTime
            float _cookingTime;

            /// \brief Store the cookNumber
            size_t _cookNumber;

            /// \brief Store the refillTime
            size_t _refillTime;

            /// \brief Maps the number of available pizza slots to the pid of a forked kitchen
            std::map<pid_t, unsigned int> _availSlots;

            /// \brief Total number of available pizza slots
            int _availSlotsTotal;
    };
}// namespace plazza

#endif /* !PLAZZA_HPP_ */
