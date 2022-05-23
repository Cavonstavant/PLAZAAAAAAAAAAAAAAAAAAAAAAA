/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Bonus
*/

#ifndef BONUS_HPP_
#define BONUS_HPP_

#include <SFML/Graphics.hpp>

#include "Plazza.hpp"

namespace plazza {
    class Bonus {
        public:
            Bonus(Reception *);
            static void run(Bonus *);
            ~Bonus();
        private:
            Reception *_reception;
            // sf::RenderWindow *_window;
    };
}

#endif /* !BONUS_HPP_ */
