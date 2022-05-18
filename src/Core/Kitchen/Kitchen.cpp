/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Kitchen
*/

/// \file src/Core/Kitchen/Kitchen.cpp

#include "Kitchen.hpp"
#include <ctime>
#include <functional>

using namespace plazza;

void Kitchen::start()
{
    _oldTime = std::time(nullptr);
    _fillFridge(5, *this);
    for (std::size_t i = 0; i < _nbCooks; ++i)
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
        _waitToFillFridge(obj->_refillTime, *obj);
        order();
    }
}

void Kitchen::enqueueJob(std::function<void()> &job)
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
    for (std::thread &active_thread: _brigade) {
        active_thread.join();
    }
    _brigade.clear();
}

void Kitchen::_fillFridge(const std::size_t &timeToFill, Kitchen &obj)
{
    for (std::size_t x = 0; x < IngredientNumber; ++x) {
        obj._fridge[x].number += timeToFill;
    }
}

void Kitchen::_waitToFillFridge(const std::size_t &timeToWait, Kitchen &obj)
{
    if (std::time(nullptr) - obj._oldTime > timeToWait) {
        obj._oldTime = std::time(nullptr);
        _fillFridge(1, obj);
    }
}
