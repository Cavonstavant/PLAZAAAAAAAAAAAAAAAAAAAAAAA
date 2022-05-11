/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Kitchen
*/

#include "Kitchen.hpp"
#include <functional>

using namespace plazza;

void Kitchen::start()
{
    _brigade.reserve(_nbCooks);
    for (size_t i = 0; i < _nbCooks; i++)
        _brigade.at(i) = std::thread(_Cook);
}

void Kitchen::_Cook()
{
    while (true) {
        std::function<void()> order;
        {
            std::unique_lock<std::mutex> lock(_mutex);
            order_condition.wait(lock, [this] {
                return !_orders.empty() || _stopKitchen;
            });
            if (_stopKitchen)
                return;
            order = _orders.front();
            _orders.pop();
        }
        order();
    }
}