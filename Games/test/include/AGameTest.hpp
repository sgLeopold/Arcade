/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGameTest
*/

#pragma once
#include "../../Interface/AGame.hpp"

class AGameTest : public AGame
{
    private:
        void upKeyPress();
        void downKeyPress();
        void leftKeyPress();
        void rightKeyPress();
        IEvent::EventHandler gameEvent;

    public:
        AGameTest() = default;
        ~AGameTest() = default;

        IEvent::EventHandler &getEventBinding() final;
        void processGameTick(IClock &clock) final;
        std::vector<IEntity> getEntity() final;
};
