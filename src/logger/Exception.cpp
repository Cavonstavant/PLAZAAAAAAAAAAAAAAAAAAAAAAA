/*
** EPITECH PROJECT, 2022
** constant.vigneron@epitech.eu
** File description:
** Exception
*/

/// \file src/logger/Exception.cpp

#include "Exception.hpp"
#include "Logger.hpp"
#include <sstream>

PlazzaException::PlazzaException(std::string const &what, std::string const &func, int const &line, std::string const &file) : _name("PlazzaException")
{
    std::stringstream ss;

    _what = what;
    _func = func;
    _line = line;
    _file = file;

    ss << func << " (" << file << ":" << line << ")";
    _where = ss.str();
}

const char *PlazzaException::what() const noexcept
{
    return _what.c_str();
}

const std::string &PlazzaException::where() const noexcept
{
    return _where;
}

const std::string &PlazzaException::getFunc() const noexcept
{
    return _func;
}

const std::string &PlazzaException::getFile() const noexcept
{
    return _file;
}

const int &PlazzaException::getLine() const noexcept
{
    return _line;
}

const std::string &PlazzaException::getName() const noexcept
{
    return _name;
}
