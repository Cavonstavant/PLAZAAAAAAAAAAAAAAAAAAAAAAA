/*
** EPITECH PROJECT, 2022
** constant.vigneron@epitech.eu
** File description:
** Exception
*/

/// \file src/logger/Exception.hpp

#ifndef Plazza_EXCEPTION_HPP
#define Plazza_EXCEPTION_HPP

#include "Logger.hpp"
#include <exception>
#include <string>

/// \Defines the params taken by the exceptions in addition to the "what" message
#define EX_PARAMS __PRETTY_FUNCTION__, __LINE__, __FILE__

/// \Get the exception and log it if necessary
#define ExceptionTernary(exception, what, severity) (severity() == Logger::Severity::SEVERITY_NONE ? exception(what, EX_PARAMS) : Logger::log(exception(what, EX_PARAMS), severity()))

/// \These defines makes possible to specify the function, the file and the line where the exception is thrown
/// \You MUST NOT throw the classical *Exceptions (ex: PlazzaException) but use the macros below
#define PlazzaEX(what, severity) ExceptionTernary(PlazzaException, what, severity)
#define VeryStupidUserEX(what, severity) ExceptionTernary(VeryStupidUserException, what, severity)
#define ParserEX(what, severity) ExceptionTernary(ParserException, what, severity)
#define MessageTooLongEX(what, severity) ExceptionTernary(MessageTooLongException, what, severity)

/// \Defines the color codes to print the exceptions in color
#define LOGGER_COLOR_RESET "\x1B[0m"
#define LOGGER_COLOR_BLACK "\x1B[30m"
#define LOGGER_COLOR_RED "\x1B[31m"
#define LOGGER_COLOR_GREEN "\x1B[32m"
#define LOGGER_COLOR_YELLOW "\x1B[33m"
#define LOGGER_COLOR_BLUE "\x1B[34m"
#define LOGGER_COLOR_PURPLE "\x1B[35m"
#define LOGGER_COLOR_CYAN "\x1B[36m"
#define LOGGER_COLOR_WHITE "\x1B[37m"
#define LOGGER_COLOR_BOLD "\x1B[1m"

/// \brief Base exception class for all exceptions in the project
class PlazzaException : public std::exception {
public:
    /// \brief DO NOT USE THIS CONSTRUCTOR, PLEASE USE THE MACROS DEFINED ABOVE IN EXCEPTION.HPP (PlazzaEX, ...)
    /// \param what The description of the exception
    /// \param func The function where the exception is thrown
    /// \param file The file where the exception is thrown
    /// \param line The line where the exception is thrown
    explicit PlazzaException(std::string const &what, std::string const &func, int const &line, std::string const &file);
    /// \brief returns the description of the exception
    /// \return the description of the exception
    [[nodiscard]] const char *what() const noexcept override;
    /// \brief returns where the exception is thrown
    /// \return the where the exception has been thrown
    [[nodiscard]] const std::string &where() const noexcept;
    /// \brief returns the function where the exception is thrown
    /// \return the function where the exception is thrown
    [[nodiscard]] const std::string &getFunc() const noexcept;
    /// \brief returns the file where the exception is thrown
    /// \return the file where the exception is thrown
    [[nodiscard]] const std::string &getFile() const noexcept;
    /// \brief returns the line where the exception is thrown
    /// \return the line where the exception is thrown
    [[nodiscard]] const int &getLine() const noexcept;
    /// \brief returns the name of the exception
    /// \return the name of the exception
    [[nodiscard]] const std::string &getName() const noexcept;

protected:
    std::string _name;
    std::string _what;
    std::string _where;
    std::string _func;
    std::string _file;
    int _line;

private:
};

/// \brief Exception class to throw when something is not implemented
class NotImplementedException : public PlazzaException {
public:
    NotImplementedException(std::string const &what, std::string const &func, int const &line, std::string const &file) : PlazzaException(what, func, line, file)
    {
        _name = "NotImplementedException";
    };
};

/// \brief Base Exception class for any exception related to Message Queues
class MessageQueueException : public PlazzaException {
public:
    MessageQueueException(std::string const &what, std::string const &func, int const &line, std::string const &file) : PlazzaException(what, func, line, file)
    {
        _name = "MessageQueueException";
    };
};

class MessageTooLongException : public MessageQueueException {
public:
    MessageTooLongException(std::string const &what, std::string const &func, int const &line, std::string const &file) : MessageQueueException(what, func, line, file)
    {
        _name = "MessageTooLongException";
    };
};

/// \brief Exception class when a user is very stupid and we can't do what anything for them
class VeryStupidUserException : public PlazzaException {
public:
    explicit VeryStupidUserException(std::string const &what = "", std::string const &func = "", int const &line = 0, std::string const &file = "") : PlazzaException("Please stop", "You probably need to restart your project from scratch", 0, "User IQ")
    {
        _name = "VeryStupidUserException";
        (void) what;
        (void) func;
        (void) line;
        (void) file;
    };
};

class ParserException : public PlazzaException {
public:
    ParserException(std::string const &what, std::string const &func, int const &line, std::string const &file) : PlazzaException(what, func, line, file)
    {
        _name = "ParserException";
    };
};

#endif /* !PLAZZA_EXCEPTION_HPP */
