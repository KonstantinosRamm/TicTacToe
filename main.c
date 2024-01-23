#include <stdio.h>
#include <stdlib.h>//exit function
#include "tictactoe.h"


int main(void){
    char board[boardSize] = {"123456789"};
    char player = 'X';
    int counter = 0;//counter of rounds for the draw statement

    printStatus(welcome);
    printBoard(board);

    while(true){
        if(input(board,player) == player){//checks if the input was correct to increase the counter
            counter++;//increase counter for each sucessful round


        }
        if(gameLogic(board) == true){//if the function returns true then check who is the winner
        clear_screen();
            if(player == 'X'){
                
                printStatus(win_X);//print x wins
            }
            else{
                printStatus(win_O);//print o wins
            }
            exit(0);//exit game
        }
        if(gameLogic(board) != true && counter >= max_rounds){//draw case
            clear_screen();
            printStatus(draw);//print draw
            exit(0);
        }
        playerTurn(&player);//change player
        clear_screen();//clear the screen
        printBoard(board);//printthe updated board
    }
    


    return 0;
}


