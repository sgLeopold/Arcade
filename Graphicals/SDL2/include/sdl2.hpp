/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** sdl2
*/

#ifndef SDL2_HPP_
    #define SDL2_HPP_
    #include "../../../Core/include/various.hpp"
    #include "../../../Interface/Graphical/IGraphicals.hpp"
    #include <SDL2/SDL.h>

struct GraphicalInfo {
    SDL_Window *window;
    SDL_Event event;
    bool isOpen;

    GraphicalInfo()
        : window(nullptr)
        , event({})
        , isOpen(false)
    {}
};

class AGraphical: public IGraphical {
private:
    EventHandler *_eventBinding;
    std::unordered_map<int, bool> keyState;
    GraphicalInfo graphicalInfo;

    void callEvent(const IEvent::EventType);

public:
    AGraphical(): _eventBinding{ nullptr} {};
    ~AGraphical() {};

    // IGraphical
    virtual void loadResource() {};
    virtual void resetResource() {};

    //IWindow
    virtual void openWindow() final;
    virtual void closeWindow() final;
    virtual void initWindow(std::string, std::pair<size_t, size_t>) final;
    virtual bool windowIsOpen() final;
    virtual void clear() final;
    virtual void display() final;

    //IEvent
    virtual void loadEventBindings(EventHandler &) final;

    // IEntity
    virtual void create() final {};

    virtual void setSize() final {};

    virtual void setPosition() final {};

    virtual void destroy() final {};

    virtual void displayEntity() final {};
};

#endif /* !SDL2_HPP_ */
