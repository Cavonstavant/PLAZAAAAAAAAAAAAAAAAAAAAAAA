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
            Core(size_t cookingTime = 0, size_t cookNumber = 0, size_t refillTime = 0);

            ~Core();
        private:
            size_t _cookingTime;
            size_t _cookNumber;
            size_t _refillTime;

    };
}

#endif /* !PLAZZA_HPP_ */
