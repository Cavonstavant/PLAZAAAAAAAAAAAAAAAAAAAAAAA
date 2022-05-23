/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Bonus
*/

#include "Bonus.hpp"
#include <iostream>

using namespace plazza;

Bonus::Bonus(Reception *reception)
{
    _font.loadFromFile("./arial.ttf");
    _reception = reception;
}

void Bonus::drawGrill(Bonus *obj)
{
    sf::RectangleShape shape;

    for (std::size_t x = 1; x < 3; x++) {
        shape.setOutlineColor(sf::Color::White);
        shape.setOutlineThickness(1);
        shape.setPosition(obj->_window->getSize().x / 3 * x, 0);
        shape.setSize({0, obj->_window->getSize().y});
        obj->_window->draw(shape);
    }
    for (std::size_t x = 1; x < 3; x++) {
        shape.setOutlineColor(sf::Color::White);
        shape.setOutlineThickness(1);
        shape.setPosition(0, obj->_window->getSize().y / 3 * x);
        shape.setSize({obj->_window->getSize().x, 0});
        obj->_window->draw(shape);
    }
}

void Bonus::drawModules(Bonus *obj)
{
    std::size_t index = 0;
    sf::RectangleShape shape;
    sf::Text text;
    std::string message;
    std::string tmp;
    std::map<pid_t, std::shared_ptr<MessageQueue>>::iterator kitchen;

    shape.setSize({obj->_window->getSize().x / 3, obj->_window->getSize().y / 3});
    shape.setFillColor(sf::Color::Green);
    text.setFont(obj->_font);
    text.setFillColor(sf::Color::Black);
    {
        std::unique_lock<std::mutex> lock(obj->_reception->_mutex);
        if (obj->_reception->_kitchenMap.empty()) {
            drawGrill(obj);
            return;
        }
        kitchen = obj->_reception->_kitchenMap.begin();
    }
    while (true) {
        message.clear();
        shape.setPosition(obj->_window->getSize().x * (index % 3) / 3, obj->_window->getSize().y * (index / 3) / 3);
        obj->_window->draw(shape);
        message.append("Kitchen: " + std::to_string(kitchen->first));
        message.append("\nFridge:\n");
        {
            std::unique_lock<std::mutex> lock(obj->_reception->_mutex);
            kitchen->second.get()->sendMessage("avail_slotsG?");
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        {
            std::unique_lock<std::mutex> lock(obj->_reception->_mutex);
            tmp = kitchen->second.get()->receiveMessage();
        }
        time_t oldTime = std::time(nullptr);
        while (tmp.find("avail_slotsG:") != 0) {
            {
                std::unique_lock<std::mutex> lock(obj->_reception->_mutex);
                kitchen->second.get()->sendMessage("avail_slotsG?");
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            {
                std::unique_lock<std::mutex> lock(obj->_reception->_mutex);
                tmp = kitchen->second.get()->receiveMessage();
            }
            if (std::time(nullptr) - oldTime > 3) {
                std::cout << "Time out" << std::endl;
                return;
            }
        }
        tmp = tmp.substr(tmp.find("fridge"));
        tmp = tmp.substr(tmp.find(":") + 1);
        while (!tmp.empty()) {
            message.append(tmp.substr(0, tmp.find(",")) + ": ");
            tmp = tmp.substr(tmp.find(",") + 1);
            message.append(tmp.substr(0, tmp.find(";")) + "\n");
            tmp = tmp.substr(tmp.find(";") + 1);
        }
        text.setString(message);
        text.setCharacterSize(16);
        text.setPosition(shape.getPosition().x + 5, shape.getPosition().y + 5);
        obj->_window->draw(text);
        {
            std::unique_lock<std::mutex> lock(obj->_reception->_mutex);
            ++kitchen;
            if (kitchen == obj->_reception->_kitchenMap.end())
                break;
        }
        index++;
    }
    drawGrill(obj);
}

void Bonus::newOrder(Bonus *obj)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "Plazza - NewOrder", sf::Style::Fullscreen);
    sf::Event event;
    std::vector<Button> buttons;
    Button button(obj->_font, "validate");

    button.shape.setPosition(window.getSize().x / 2 - button.shape.getSize().x / 2, window.getSize().y - button.shape.getSize().y);
    button.text.setPosition(button.shape.getPosition());
    buttons.push_back(button);
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        auto pos = sf::Mouse::getPosition(window);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::MouseButtonPressed) {
                window.close();
            }
        }
        window.clear();
        for (auto it: buttons) {
            if (pos.x > button.shape.getPosition().x && pos.x < button.shape.getPosition().x + button.shape.getSize().x && pos.y > button.shape.getPosition().y && pos.y < button.shape.getPosition().y + button.shape.getSize().y) {
                button.shape.setFillColor(sf::Color::Green);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    std::cout << "validate" << std::endl;
                    obj->_reception->_handleInput("regina XL x10");
                }
            } else
                button.shape.setFillColor(sf::Color::Red);
            window.draw(button.shape);
            window.draw(button.text);
        }
        window.display();
    }
}

void Bonus::run(Bonus *obj)
{
    sf::Event event;

    obj->_window = new sf::RenderWindow(sf::VideoMode(1920, 1080, 32), "Plazza", sf::Style::Default);
    obj->_window->setFramerateLimit(1);
    while (obj->_window->isOpen()) {
        while (obj->_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                obj->_window->close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::O)
                newOrder(obj);
        }
        obj->_window->clear(sf::Color::Red);
        drawModules(obj);
        obj->_window->display();
    }
    delete obj->_window;
}

Bonus::~Bonus()
{
}

Bonus::Button::Button(sf::Font &font, std::string texte)
{
    shape.setSize({200, 50});
    shape.setFillColor(sf::Color::Red);
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(16);
    text.setString(texte);
}

Bonus::Button::~Button()
{
}