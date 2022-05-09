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

namespace plazza {
    /// \brief Core Class containing the main loop of the program
    class Core {
        public:
            /// \brief Default Constructor of the Core class DO NOT USE or it will lead to undefined comportements
            Core() = default;
            /// \brief Construct the Core with the necessary parameters for the method run()
            /// \param cookingTime needs to be get of an ArgumentsParser Object with getCookingTime() method
            /// \param cookNumber needs to be get of an ArgumentsParser Object with getCookNumber() method
            /// \param refillTime needs to be get of an ArgumentsParser Object with getRefillTime() method
            Core(size_t cookingTime, size_t cookNumber, size_t refillTime);
            /// \brief Default Constructor of the Core
            ~Core() = default;
            /// \brief Main function of the program
            void run();

        private:
            /// \brief Store the cookingTime
            size_t _cookingTime;
            /// \brief Store the cookNumber
            size_t _cookNumber;
            /// \brief Store the refillTime
            size_t _refillTime;
    };
}// namespace plazza

#endif /* !PLAZZA_HPP_ */
