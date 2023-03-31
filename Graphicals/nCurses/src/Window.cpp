/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Window
*/

#include "GraphicalFactoryNcurses.hpp"
#include <ncurses.h>

void WindowNcurses::initWindow(std::string name, size_t width, size_t height)
{
    std::cout << "[nCurses] initWindow" << std::endl;
    std::cout.setstate(std::ios_base::failbit);
    initscr();
    cbreak();
    noecho();

    getmaxyx(stdscr, yMax, xMax);
    _window = newwin(height, width, yMax / 2, xMax / 2);
    box(_window, 0, 0);
    refresh();
    wrefresh(_window);
    nodelay(_window, TRUE);
    isOpen = true;
};

void WindowNcurses::closeWindow()
{
    std::cout << "[nCurses] closeWindow" << std::endl;
    isOpen = false;
    endwin();
};

bool WindowNcurses::windowIsOpen()
{
    return isOpen;
};

void WindowNcurses::clear()
{
};


void WindowNcurses::display()
{
    // mvwprintw(_window, 1, xMax / 3 - 15, "Arcade");
};

void WindowNcurses::eventPollEvent()
{
    int key = wgetch(_window);

    switch (key) {
    case -1:
        return;
    case 'z':
    case KEY_UP:
        return callEvent(IWindow::EventType::UP_pressed);

    case 's':
    case KEY_DOWN:
        return callEvent(IWindow::EventType::DOWN_pressed);

    case 'q':
    case KEY_LEFT:
        return callEvent(IWindow::EventType::LEFT_pressed);

    case 'd':
    case KEY_RIGHT:
        return callEvent(IWindow::EventType::RIGHT_pressed);

    case 'n':
    return callEvent(IWindow::EventType::NEXT_LIB);

    case 27:
        return callEvent(IWindow::IWindow::EventType::QUIT);

    default:
        std::cerr << "--! Event Handler Unknown key: " << key << std::endl;
        break;
    }
};

void WindowNcurses::callEvent(const IWindow::EventType eventType) {
    if (_eventBinding.count(eventType) <= 0)
        throw std::runtime_error("--! [GAME Logic] no event binded");
    _eventBinding[eventType]();
}

void WindowNcurses::loadEventBindings(EventHandler &eventBinding) {
    _eventBinding.insert(eventBinding.begin(), eventBinding.end());
};

std::unique_ptr<IText> WindowNcurses::createIText() {
    return std::make_unique<TextNcurses>(_window);
}

std::unique_ptr<IGrid> WindowNcurses::createIGrid() {
   return std::make_unique<GridNcurses>(_window);
}