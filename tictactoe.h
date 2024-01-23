#define true 1
#define false 0
#define boardSize 9//size of the board
//various states of the game according to win or draw
#define win_O 1
#define win_X 2
#define draw 3
#define welcome 4
#define game_on_progress -1
#define error '0' //return state for input error by user
#define max_rounds 9 //if the max rounds pass we gonna have a draw

void printBoard(char board[]);//create the board
void playerTurn(char *player);//count the player turn
void printStatus(int state);//some simple graphics to represent win draw and welcome messages
int gameLogic(char board[]);//implementation of tic tac toe logic to check for winner or draw
char input(char board[],char player);//user input
void clear_screen();//virtually clear terminal screen