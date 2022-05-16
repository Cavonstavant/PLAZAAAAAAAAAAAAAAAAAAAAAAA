/*
** EPITECH PROJECT, 2022
** constant.vigneron@epitech.eu
** File description:
** Logger
*/

/// \file src/logger/logger.cpp

#include "Logger.hpp"
#include "Exception.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

static std::string getSeverityColor(Logger::Severity severity)
{
    switch (severity) {
        case Logger::SEVERITY_LOW:
            return LOGGER_COLOR_GREEN;
        case Logger::SEVERITY_MEDIUM:
            return LOGGER_COLOR_YELLOW;
        case Logger::SEVERITY_HIGH:
            return LOGGER_COLOR_RED;
        case Logger::SEVERITY_CRITICAL:
            return LOGGER_COLOR_PURPLE;
        case Logger::SEVERITY_INFO:
            return LOGGER_COLOR_CYAN;
        default:
            return LOGGER_COLOR_RESET;
    }
}

static std::string getSeverityString(Logger::Severity severity)
{
    switch (severity) {
        case Logger::Severity::SEVERITY_LOW:
            return "LOW";
        case Logger::Severity::SEVERITY_MEDIUM:
            return "MEDIUM";
        case Logger::Severity::SEVERITY_HIGH:
            return "HIGH";
        case Logger::Severity::SEVERITY_CRITICAL:
            return "CRITICAL";
        case Logger::Severity::SEVERITY_INFO:
            return "INFO";
        default:
            return "MEDIUM";
    }
}

PlazzaException Logger::log(PlazzaException ex, Severity severity)
{
    std::stringstream ssColor;
    std::stringstream ss;
    std::ofstream ofLog;
    std::string severityString = getSeverityString(severity);
    std::string severityColor = getSeverityColor(severity);

    ssColor << "[LOGGER:" << severityColor << severityString << LOGGER_COLOR_RESET << "] " << severityColor << LOGGER_COLOR_BOLD << ex.getName() << LOGGER_COLOR_RESET << " >> " << LOGGER_COLOR_BOLD << ex.what() << LOGGER_COLOR_RESET << std::endl;
    ssColor << LOGGER_COLOR_RED << ">> " << LOGGER_COLOR_WHITE << LOGGER_COLOR_BOLD << ex.getFunc() << LOGGER_COLOR_RESET << " (" << ex.getFile() << ":" << ex.getLine() << ")" << std::endl;
    std::cerr << ssColor.str() << std::endl;

    try {
        ss << "[LOGGER:" << severityString << "] " << ex.getName() << " >> " << ex.what() << std::endl;
        ss << ">> " << ex.getFunc() << " (" << ex.getFile() << ":" << ex.getLine() << ")" << std::endl;
        ofLog.open("Plazza.log", std::ios::app);
        ofLog << ss.str() << std::endl;
        ofLog.close();
    } catch (std::exception &e) {
        std::cerr << "Logging into 'Plazza.log' file failed (" << e.what() << ")" << std::endl;
    }
    return ex;
}

Logger::Severity Logger::NONE()
{
    return Severity::SEVERITY_NONE;
}

Logger::Severity Logger::LOW()
{
    return Severity::SEVERITY_LOW;
}

Logger::Severity Logger::MEDIUM()
{
    return Severity::SEVERITY_MEDIUM;
}

Logger::Severity Logger::HIGH()
{
    return Severity::SEVERITY_HIGH;
}

Logger::Severity Logger::CRITICAL()
{
    return Severity::SEVERITY_CRITICAL;
}

Logger::Severity Logger::INFO()
{
    return Severity::SEVERITY_INFO;
}
