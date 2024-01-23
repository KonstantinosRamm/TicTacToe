#include <stdio.h>
#include "tictactoe.h"


void printBoard(char board[]){//print the board 
    printf("\n");
    printf("\t\t\t             %c   |  %c  |   %c   \n",board[0],board[1],board[2]);
    printf("\t\t\t           ********************** \n");
    printf("\t\t\t             %c   |  %c  |   %c   \n",board[3],board[4],board[5]);
    printf("\t\t\t           ********************** \n");
    printf("\t\t\t             %c   |  %c  |   %c   \n",board[6],board[7],board[8]);

}

void playerTurn(char *player){//swap turns between players
    if(*player == 'X'){
        *player = 'O';
    }
    else{
        *player = 'X';
    }
}

void printStatus(int state){
    switch (state){
        case win_O:
        printf("\n");
    printf("\n .d88b.      db   d8b   db d888888b d8b   db .d8888.");                                 
    printf("\n.8P  Y8.     88   I8I   88   `88'   888o  88 88'  YP");                                 
    printf("\n88    88     88   I8I   88    88    88V8o 88 `8bo.  ");                                 
    printf("\n88    88     Y8   I8I   88    88    88 V8o88   `Y8b.");                                 
    printf("\n`8b  d8'     `8b d8'8b d8'   .88.   88  V888 db   8D");                                 
    printf("\n `Y88P'       `8b8' `8d8'  Y888888P VP   V8P `8888Y'"); 
        break;

        case win_X:
        printf("\n");
    printf("\ndb    db     db   d8b   db d888888b d8b   db .d8888.");                                 
    printf("\n`8b  d8'     88   I8I   88   `88'   888o  88 88'  YP");                                 
    printf("\n `8bd8'      88   I8I   88    88    88V8o 88 `8bo.  ");                                 
    printf("\n .dPYb.      Y8   I8I   88    88    88 V8o88   `Y8b.");                                 
    printf("\n.8P  Y8.     `8b d8'8b d8'   .88.   88  V888 db   8D");                                 
    printf("\nYP    YP      `8b8' `8d8'  Y888888P VP   V8P `8888Y'");   
        break;

        case draw:
        printf("\n");
    printf("\nd8888b. d8888b.  .d8b.  db   d8b   db");                                                
    printf("\n88  `8D 88  `8D d8' `8b 88   I8I   88");                                                
    printf("\n88   88 88oobY' 88ooo88 88   I8I   88");                                                
    printf("\n88   88 88`8b   88~~~88 Y8   I8I   88");                                                
    printf("\n88  .8D 88 `88. 88   88 `8b d8'8b d8'");                                                
    printf("\nY8888D' 88   YD YP   YP  `8b8' `8d8' ");   
        break;

        case welcome:
    printf("\nd888888b d888888b  .o88b.     d888888b  .d8b.   .o88b.     d888888b  .d88b.  d88888b"); 
    printf("\n`~~88~~'   `88'   d8P  Y8     `~~88~~' d8' `8b d8P  Y8     `~~88~~' .8P  Y8. 88'    "); 
    printf("\n   88       88    8P             88    88ooo88 8P             88    88    88 88ooooo"); 
    printf("\n   88       88    8b             88    88~~~88 8b             88    88    88 88~~~~~"); 
    printf("\n   88      .88.   Y8b  d8        88    88   88 Y8b  d8        88    `8b  d8' 88.    "); 
    printf("\n   YP    Y888888P  `Y88P'        YP    YP   YP  `Y88P'        YP     `Y88P'  Y88888P");
    printf("\n");
    break;
    }
}




int gameLogic(char board[]){//implementation of tic tac toe logic to check for winner or draw
    
    if((board[0] == board[1] && board[1] == board[2]) ||
       (board[3] == board[4] && board[4] == board[5]) ||
       (board[6] == board[7] && board[7] == board[8]) ||
       (board[0] == board[3] && board[3] == board[6]) ||
       (board[1] == board[4] && board[4] == board[7]) ||
       (board[2] == board[5] && board[5] == board[8]) ||
       (board[0] == board[4] && board[4] == board[8]) ||
       (board[6] == board[4] && board[4] == board[2]) ){
        return true;
        }

    return game_on_progress;
    
}


char input(char board[],char player){//user input

    while(true){
        printf("\n%c turn.choose a cell between 1 and 9 that is not occupied:",player);
        char input = getchar();
        int input_convert = input - '0' -1; //convert the character into number

        if((input_convert > 9 || input_convert < 0) || (board[input_convert] == 'X' || board[input_convert] == 'O') ){
            printf("\ninvalid choise.Try again...");
        }
        else{
            board[input_convert] = player;//if the input was correct input the choise in the board

            while((input = getchar()) != '\n'){//error handling
                continue;
            }
            return player;//return the current player
            break;//exit the loop if the input was correct
        }

            while((input = getchar()) != '\n'){//error handling
            continue;
            }

    }
    return error;

}

void clear_screen(){//clear screen
    for(int i = 0; i < 100; i++){
        printf("\n");
    }
}