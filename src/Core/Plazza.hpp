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

namespace Plazza
{
    class Core {
        public:
            Core() = default;

            Core(size_t cookingTime, size_t cookNumber, size_t refillTime);

            ~Core() = default;

            void run();
        private:
            size_t _cookingTime;
            size_t _cookNumber;
            size_t _refillTime;

    };
}

#endif /* !PLAZZA_HPP_ */
