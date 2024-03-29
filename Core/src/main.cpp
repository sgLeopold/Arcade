/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** main
*/

#include "Core/Core.hpp"
#include <iostream>
#include <exception>

int main(const int ac, const char **av)
{
    try {
        if (ac != 2) throw std::invalid_argument("invalid arguments");
        coreEntryPoint(av[1]);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return 84;
    }
    return 0;
}
