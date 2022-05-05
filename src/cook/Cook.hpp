/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Cook
*/

#pragma once

#include <string>
#include <vector>

namespace plazza {
    class Cook {
        public:
            Cook();
            Cook(const std::string);
            ~Cook() = default;
            void cookTakeThisCommand(const std::string);
            void removeIngredientsFromFridge(const std::vector<std::string>);
        private:
            void _setIngredientsListFromCommand(void);
            std::string _IHaveToMakeThisPizza;
            bool _IHaveACommand;
    };
}
