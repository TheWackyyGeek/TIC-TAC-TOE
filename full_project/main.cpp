#include <iostream>

char board[3][3] = {{' ',' ',' '},
                    {' ',' ',' '},
                    {' ',' ',' '}}; 


void printBoad()
{
    int postiton ;
        std::cout<<std::endl<<"-------------"<<std::endl;
    for (int i = 0 ; i < 3; i++){
        for (int j = 0 ; j < 3 ; j++){
            std::cout<<" | "<<board[i][j];
        }
        std::cout<<" | "<<std::endl<<"--------------"<<std::endl;
    }
}

void updateboard()
{
    int posx , posy ;
     char swap_symbol = 'X';
     std::cin>>posx>>posy;

    board[posx-1][posy-1] = swap_symbol;
}

int main(){
    int position = 0 ;
    bool runningLoop = true;
    while (runningLoop)
    {
        system("cls");
        printBoad();
        updateboard();
    }



    return 0;
}