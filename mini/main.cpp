#include <iostream>

char board[3][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '}};

void printBoad()
{
    int postiton;
    std::cout << std::endl
              << " -------------" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << " | " << board[i][j];
        }
        std::cout << " | " << std::endl
                  << " --------------" << std::endl;
    }
}

bool updateboard()
{
    int posx, posy;
    char swap_symbol = 'X';

    std::cin >> posx >> posy;
    board[posx - 1][posy - 1] = swap_symbol;

    return ((posx > 0 && posx < 4) && (posy > 0 && posy < 4)) ? true : false;
}

bool checkWinner()
{
    int winnerCounter = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 9; j += 3)
        {
            if(board[i][j] == 'x')
            {winnerCounter++;}
        }
    }
    std::cout << "winner count "<<winnerCounter <<std::endl;
    if (winnerCounter >= 3){
        return true;
    }else{return false;}
}

int main()
{
    bool runningLoop = true;
    bool winnerX = false;
    while (runningLoop)
    {
        system("cls");
        printBoad();
        if (winnerX )
        {
            break;
        }
        winnerX = checkWinner();
        
        runningLoop = updateboard();
        
    }
    
    if (winnerX){
        std::cout<<"X person won this Game !!"<<std::endl;
    }

    std::cout << "Thanks for playing this game!!" << std::endl;

    return 0;
}
