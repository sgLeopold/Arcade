/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** GameLib
*/


#pragma once
#include "lib/LibHandler.hpp"
#include "lib/LibFileManager.hpp"
#include "interface.hpp"

class GameLib {
private:
    LibHandler<IGame> _currentLib;

public:
    GameLib();
    ~GameLib();

    Lib::lib _libDetails;
    void load(Lib::lib);
    IGame& getInterface();
};
