#include "game.hpp"


//private functions
void game::initVariable(){
    windowState = true;
}

//public functions
game::game()
{
    initVariable();
}

game::game(windowSize winsize)
{
    setWindowSize(winsize.width,winsize.height);
    initVariable();
}
void game::clearscreen()
{
    system("cls");
}
void game::update()
{
    
}
void game::render()
{

}

