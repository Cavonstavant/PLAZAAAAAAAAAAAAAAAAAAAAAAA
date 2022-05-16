/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Kitchen
*/

/// \file src/Core/Kitchen/Kitchen.cpp

#include "Kitchen.hpp"
#include <functional>

using namespace plazza;

void Kitchen::start()
{
    for (size_t i = 0; i < _nbCooks; ++i)
        _brigade.emplace_back(std::thread(_Cook, this));
}

void Kitchen::_Cook(Kitchen *obj)
{
    while (true) {
        std::function<void()> order;
        {
            std::unique_lock<std::mutex> lock(obj->_mutex);
            obj->order_condition.wait(lock, [&obj] {
                return !obj->_orders.empty() || obj->_stopKitchen;
            });
            if (obj->_stopKitchen)
                return;
            order = obj->_orders.front();
            obj->_orders.pop();
        }
        order();
    }
}

void Kitchen::enqueueJob(std::function<void()>& job)
{
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _orders.push(job);
    }
    order_condition.notify_one();
}

void Kitchen::stop()
{
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _stopKitchen = true;
    }
    order_condition.notify_all();
    for (std::thread& active_thread : _brigade) {
        active_thread.join();
    }    _brigade.clear();
}