/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAA
** File description:
** Plazza
*/

/// \file src/Core/Plazza.hpp

#ifndef PLAZZA_HPP_
#define PLAZZA_HPP_

#include <cstddef>
#include <string>
#include "Pizza.hpp"

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
    Reception(size_t cookingTime, size_t cookNumber, size_t refillTime);
    /// \brief Default Constructor of the Reception
    ~Reception() = default;
    std::string pack(const Pizza &);
    Pizza unpack(const std::string &);
    /// \brief Main function of the program
    void run();

private:
    /// \brief Display all of the kitchens current status
    void _displayKitchensStatus(void);
    /// \brief Handle the receive input
    /// \return true if the input is valid, false otherwise
    bool _handleInput(const std::string &input);
    /// \brief Store the cookingTime
    size_t _cookingTime;
    /// \brief Store the cookNumber
    size_t _cookNumber;
    /// \brief Store the refillTime
    size_t _refillTime;
};
}// namespace plazza

#endif /* !PLAZZA_HPP_ */
