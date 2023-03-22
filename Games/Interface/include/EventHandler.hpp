/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** EventHandler
*/

#ifndef EVENTHANDLER_HPP_
    #define EVENTHANDLER_HPP_
    #include "various.hpp"

class EventHandler {
public:
    EventHandler();
    ~EventHandler();

    void upKeyPress();

    void downKeyPress();

    void leftKeyPress();

    void rightKeyPress();

    IEvent::EventHandler &getEventBindings();

protected:
    IEvent::EventHandler eventHandler;
};

#endif /* !EVENTHANDLER_HPP_ */