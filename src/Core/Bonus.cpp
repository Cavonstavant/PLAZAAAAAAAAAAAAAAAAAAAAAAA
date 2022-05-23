/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Bonus
*/

#include "Bonus.hpp"

using namespace plazza;

Bonus::Bonus(Reception *reception)
{
    _reception = reception;
}

void Bonus::run(Bonus *obj)
{
    // sf::Event event;
    (void) obj;
    // obj->_window = new sf::RenderWindow(sf::VideoMode(1920, 1080, 32), "Plazza", sf::Style::Default);
    // obj->_window->setFramerateLimit(60);
    // while (obj->_window->isOpen()) {
    //     while (obj->_window->pollEvent(event)) {
    //         if (event.type == sf::Event::Closed)
    //             obj->_window->close();
    //     }
    //     obj->_window->clear();
    //     obj->_window->display();
    // }
    // delete obj->_window;
}

Bonus::~Bonus()
{
}
