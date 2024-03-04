#include <iostream>

char board[3][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '}};

void clearScreen(){
    system("cls");
}

bool isBoardFilled(){
    int isFilled = 0 ; 
    for (int i = 0 ; i < 3 ; i ++){
        for (int j = 0 ; j < 3 ; j++){
            if (board[i][j] != ' ')
            {
                isFilled++;
            }
        }
    }
    return (isFilled == 9) ? true : false;
}


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

    std::cout << getSpace(' ', 13) << "TIC TAC TOE\n\n";
    std::cout <<  getSpace('-', 13) << std::endl;
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

void printWinner(char won){
    
     if (won == 'X')
    {
        std::cout << "X won this Game !!" << std::endl;
    }
    else if (won == 'O')
    {
        std::cout << "O won this Game !!" << std::endl;
    }
    else if(isBoardFilled()){
        std::cout<<"This Game is Tied (= "<<std::endl; 
    }
}

bool updateboard(char swap_symbol, std::string println)
{
    int posx, posy;
    do{
    std::cout << println;
    std::cin >> posx >> posy;
    if(board[posx - 1][posy - 1] == 'X' || board[posx - 1][posy - 1] == 'O'){
    std::cout<<"invaild input !!\n\n";
    }
    }while((board[posx-1][posy-1] == 'X' || board[posx-1][posy-1] == 'O'));

    board[posx - 1][posy - 1] = swap_symbol;

    return ((posx > 0 && posx < 4) && (posy > 0 && posy < 4)) ? true : false;
}

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
    clearScreen();
    std::cout << "Welcome to My own Tic-Tac-Toe Game !!\n";
    std::cout << "\n Press Enter to continue ->";
    std::cin.get();
    clearScreen();

    bool runningLoop = true;
    char Winner = '!';
    while (runningLoop)
    {
        clearScreen();
        printBoad();
        runningLoop = updateboard('O',"Enter the position of O: ");        
        printBoad();
        clearScreen();
        Winner = checkWinner();
        if (Winner == 'O' || Winner == 'X' || isBoardFilled() || !runningLoop)
        {
            break;
        }

        clearScreen();
        printBoad();
        runningLoop = updateboard('X',"Enter the position of X: ");
        clearScreen();
        printBoad();
        Winner = checkWinner();
        if (Winner == 'O' || Winner == 'X' || isBoardFilled() || !runningLoop)
        {
            break;
        }
    }
    printWinner(Winner);
    std::cout<<"Thanks for playing this game!!";
    std::cin.get();
    std::cin.get();
    return 0;
}
