#include <iostream>

char board[3][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '}};

std::string getSpace(char sign, const int times, char preSign = ' ', char postSign = ' ')
{
    std::string space;
    // Adding the precharacater here
    space += preSign;
    // Filling the rest with symbol in string
    for (int i = 0; i < times; i++)
    {
        space += sign;
    }
    // Adding the postcahracter here
    space += postSign;
    return space;
}

void printBoad()
{

    std::cout << getSpace(' ', 13) << "TIC TAC TOE" << std::endl;
    std::cout << std::endl
              << getSpace('-', 13) << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << " | " << board[i][j];
        }
        std::cout << " | " << std::endl
                  << getSpace('-', 13) << std::endl;
    }
}

bool updateboard(char swap_symbol, std::string println)
{
    system("cls");
    printBoad();
    int posx, posy;
    std::cout << println;
    std::cin >> posx >> posy;
    board[posx - 1][posy - 1] = swap_symbol;

    return ((posx > 0 && posx < 4) && (posy > 0 && posy < 4)) ? true : false;
}
// pending winner checking function
char checkWinner()
{
    // horizatal check for winner
    int winnerO = 0;
    int winnerX = 0;
    for (int i = 0; i < 3; i++)
    {
        if (winnerO >= 3 || winnerX >= 3)
        {
            break;
        }
        winnerO = 0;
        winnerX = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[j][i] == 'X')
            {
                winnerX++;
            }
            if (board[j][i] == 'O')
            {
                winnerO++;
            }   
        }
        if (winnerX == 3)
            {
                return 'X';
            }
        if (winnerO == 3)
            {
                return 'O';
            }
    }
    
    // vertcile check for winner
    for (int i = 0; i < 3; i++)
    {
        if (winnerO >= 3 || winnerX >= 3)
        {
            break;
        }
        winnerO = 0;
        winnerX = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'X')
            {
                winnerX++;
            }
            if (board[i][j] == 'O')
            {
                winnerO++;
            }
        }
        if (winnerX == 3)
            {
                return 'X';
            }
            if (winnerO == 3)
            {
                return 'O';
            }
    }
     // Diagonal check for winner
    if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
        (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
        return 'X';
    if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
        (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
        return 'O';


    return '!';
}


int main()
{
    bool runningLoop = true;
    char winner = '!';
    char OPTION = 'n';
    
    system("cls");
    std::cout << "YOU WANT TO PLAY IT ALONE (y/n)?    <y is not complete dont use it>\n";
    std::cin >> OPTION;
    printBoad();
    while (runningLoop)
    {
        if (OPTION == 'n' || OPTION == 'N')
        {
            system("cls");
           
            winner = checkWinner();
            runningLoop = (updateboard('O', "Enter coordination for O : ") && updateboard('X', "Enter coordination for X : "));
            
            if (winner == 'O'||winner == 'X')
            {
                break;
            }
        }
    }

    if (winner == 'X')
    {
        std::cout << "X won this Game !!" << std::endl;
    }
    else if (winner == 'O')
    {
        std::cout << "O won this Game !!" << std::endl;
    }

    std::cout << "\nThanks for playing this game!!" << std::endl;

    return 0;
}
