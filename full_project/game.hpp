#pragma once 

#include <iostream>
#include <Windows.h>
#include "window.hpp"
#include "tic-tac-toe.hpp"

class game : public Window{
public:
    game();
    game(windowSize winsize);
    ~game();
    void clearscreen();
    void update();
    void render();
public:
    bool isWindowClose();

private:
    bool windowState;
private:
    void initVariable();
};
