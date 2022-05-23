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
            class Button {
                public:
                    Button(sf::Font &font, std::string = "");
                    ~Button();
                    sf::Text text;
                    sf::RectangleShape shape;
                    int status;
            };
            Bonus(Reception *);
            static void run(Bonus *);
            static void drawModules(Bonus *);
            static void drawGrill(Bonus *);
            static void newOrder(Bonus *);
            ~Bonus();
        private:
            sf::Font _font;
            Reception *_reception;
            sf::RenderWindow *_window;
    };
}

#endif /* !BONUS_HPP_ */
