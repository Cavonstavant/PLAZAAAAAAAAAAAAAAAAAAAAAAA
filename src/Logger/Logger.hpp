/*
** EPITECH PROJECT, 2022
** constant.vigneron@epitech.eu
** File description:
** Logger
*/

/// \file src/logger/Logger.hpp

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

class PlazzaException;

/// \brief Logger class to log exceptions
class Logger {
    public:
        enum Severity {
            SEVERITY_NONE,
            SEVERITY_LOW,
            SEVERITY_MEDIUM,
            SEVERITY_HIGH,
            SEVERITY_CRITICAL,
            SEVERITY_INFO,
            SEVERITY_ENUM_SIZE
        };
        /// \brief Deleted Constructor, this class must not be instantiated.
        Logger() = delete;
        /// \brief log the exception before throwing it
        /// \param ex the exception to log
        /// \return the exception
        static PlazzaException log(PlazzaException exception, Severity severity);
        /// \brief pass this function to the macros and they will not log the exception
        /// \return Severity::NONE
        static Severity NONE();
        /// \brief pass this function to the macros and they will log the exception with a low severity
        /// \return Severity::LOW
        static Severity LOW();
        /// \brief pass this function to the macros and they will log the exception with a medium severity
        /// \return Severity::MEDIUM
        static Severity MEDIUM();
        /// \brief pass this function to the macros and they will log the exception with a high severity
        /// \return Severity::HIGH
        static Severity HIGH();
        /// \brief pass this function to the macros and they will log the exception with a critical severity
        /// \return Severity::CRITICAL
        static Severity CRITICAL();
        /// \brief pass this function to the macros and they will log an info
        /// \return Severity::INFO
        static Severity INFO();
};

#endif /* !LOGGER_HPP_ */
