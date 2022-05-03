/*
** EPITECH PROJECT, 2022
** PLAZAAAAAAAAAAAAA
** File description:
** Plazza
*/

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
        private:
            size_t _cookingTime;
            size_t _cookNumber;
            size_t _refillTime;

    };
}

#endif /* !PLAZZA_HPP_ */
