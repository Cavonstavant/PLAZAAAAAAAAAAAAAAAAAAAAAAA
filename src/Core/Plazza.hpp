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

    /// \brief Mutex for the reception
    std::mutex _mutex;

    /// \brief This function allow the reception to communicate by the messageQueue with a kitchen
    /// \param Reception The reception instance
    static void _kitchenExit(Reception *);
    /// \brief Get the answer of avail_slots
    /// \param std::string The message get from the queue
    /// \return int The number of available cook
    int _isAvailableSlots(std::string);

    /// \brief Close the Kitchens Queues and send a kill signal
    void _cleanKitchens(void);

    /// \brief Display all of the kitchens current status
    void _displayKitchensStatus(void);

    /// \brief Handle the receive input
    /// \return true if the input is valid, false otherwise
    bool _handleInput(const std::string &input);

    /// \brief Create a kitchen if necessary, and send the command to the child process
    void _manageOrders(const InputParser &command);

    /// \brief Send amt time of pizzas to the Kitchen represented by its pid
    /// \param pizzaToCook the collection of pizzas to cook
    /// \param amt the number of pizzas to cook
    /// \param kitchenPid the pid of the kitchen to cook the pizzas
    std::vector<Pizza> _sendPizza(std::vector<Pizza> &pizzaToCook, int amt, pid_t kitchenPid);

    /// \brief Creates a new Kitchen and add it to the list of kitchens
    std::vector<Pizza> _createNewKitchen(std::vector<Pizza> &pizzaToCook, unsigned int pizzaPerKitchen);

    /// \brief Check wether the creation of a new Kitchen is necessary
    /// depending on the amount
    bool _isNewKitchenNeeded(unsigned int pizzaAmt);

    /// \brief Updates _availSlots by checking how many pizzas we can
    /// order to a kitchen
    void _updateBusyCooks(void);

    /// \brief Maps to kitchen pid to the amount of free pizzas slots
    std::map<pid_t, unsigned int> _availSlots;

    /// \brief Map of the different child process, with the linked queues
    std::map<pid_t, std::shared_ptr<MessageQueue>> _kitchenMap;

    /// \brief Store the cookingTime
    float _cookingTime;

    /// \brief Store the cookNumber
    size_t _cookNumber;

    /// \brief Store the refillTime
    size_t _refillTime;

    /// \brief Represents the total amount of pizzas to cook
    unsigned int _availSlotsTotal;

    /// \brief Boolean to ask kitchen if the need to be killed
    bool _endRun;
};
}// namespace plazza

#endif /* !PLAZZA_HPP_ */
