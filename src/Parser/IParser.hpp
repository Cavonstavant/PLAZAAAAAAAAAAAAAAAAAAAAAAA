/*
** EPITECH PROJECT, 2022
** plaza
** File description:
** IParser
*/

#ifndef IPARSER_HPP_
#define IPARSER_HPP_

#include <string>
#include <vector>

/**
 * @brief IParser class. It is a virtual class.
 *
 */
class IParser {
    public:
        /**
     * @brief Destroy the IParser object as default
     *
     */
        ~IParser() = default;
        /**
     * @brief Set the command that will be parsed.
     *
     */
        virtual void setCommand(const std::string &) = 0;
        /**
     * @brief Get the command previously set.
     *
     * @return const std::string& of the command.
     * It return an empty std::string in case of undefined command.
     */
        virtual const std::string &getCommand() const = 0;
        /**
     * @brief Get the number of arguments in the command.
     *
     * @return const std::size_t&, the number of arguments.
     */
        virtual const std::size_t &getArgumentNumber() const = 0;
        /**
     * @brief This function will be set differently by the children
     *
     */
        virtual void prossessArguments() = 0;
        /**
     * @brief Set a char that will be the separator on each command.
     *
     */
        virtual void setCommandSeparator(char) = 0;
        /**
     * @brief Get the a list of all arguments in the command.
     *
     * @return const std::vector<std::string>& that contain each argument.
     */
        virtual const std::vector<std::string> &getArguments() const = 0;
};

#endif
