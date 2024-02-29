#include <iostream>

char board[3][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '}};

void printBoad()
{
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
    int winnerCounterX = 1;
    int winnerCounterY = 1;

    // Horizontal check
    for (int i = 0; i < 3; i++)
    {
        winnerCounterY = 1;
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'x')
                winnerCounterY++;
        }
    }

    // Vertical check
    for (int i = 0; i < 3; i++)
    {
        winnerCounterX = 1;
        for (int j = 0; j < 3; j++)
        {
            if (board[j][i] == 'x')
                winnerCounterX++;
        }
    }

    // Diagonal check
    if (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x')
        winnerCounterX++;
    if (board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x')
        winnerCounterX++;

    std::cout << "Winner count: " << winnerCounterX << std::endl;

    return (winnerCounterX >= 3 || winnerCounterY >= 3);
}


int main()
{
    bool runningLoop = true;
    bool winnerX = false;
    while (runningLoop)
    {
        system("cls");
        printBoad();
        if (winnerX)
        {
            break;
        }
        winnerX = checkWinner();

        runningLoop = updateboard();
    }

    if (winnerX)
    {
        std::cout << "X person won this Game !!" << std::endl;
    }

    std::cout << "Thanks for playing this game!!" << std::endl;

    return 0;
}
