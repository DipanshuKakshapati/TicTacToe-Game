#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();x
char checkWinner();
void printWinner(char);
void compPlay();


void resetBoard()
{
    for(int i = 0; i<3 ; i++)
    {
        for(int j = 0;j<3;j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board [1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int checkFreeSpaces()
{
    int freeSpaces = 9;

    for(int i = 0;  i < 3; i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!=' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}
void playerMove()
{
    int x;
    int y;

    do
    {
        printf("Enter row #(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y]!=' ')
        {
            printf("Invalid move!\n");
        }
        else
        {   
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');

}
void computerMove()
{
    // creates a seed based on current time
    srand(time(0));
    int x;
    int y;

    if(checkFreeSpaces() > 0)
    {
        do
        {
            x= rand()%3;
            y=rand()%3;
        } while (board[x][y] != ' ');

        board[x][y]= COMPUTER;  
        printf("\n\n\n\t\tYour turn!\n\n");
    }
    else{
        printWinner(' ');
    }
}
char checkWinner()
{
    // check rows
    for(int i = 0; i<3;i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    // check cloumns
   for(int i = 0; i<3;i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    // check diagonals
     if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';

}
void printWinner(char winner)
{
    if(winner == PLAYER)
    {
        printf("YOU WIN!");
    }
    else if(winner == COMPUTER)
    {
        printf("YOU LOSE!");
    }
    else{
        printf("IT'S A TIE!");
    }
}

void compPlay()
{
    char winner = ' ';
  
        resetBoard();

        while(winner == ' ' && checkFreeSpaces() != 0)
        {
            printBoard();

            playerMove();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }

            computerMove();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }
        }

        printBoard();
        printWinner(winner);

}

void selfplay();
// hihihihihihihihihiihih

void display_board(char game_board[])
{
    int i;
    for(i=0;i<9;i++)
    {
        printf("%c ",game_board[i]);
     
        // after the 3rd space the the board shifts down to print remaining spaces
        if((i+1)%3==0)
        {   
            printf("\n");
        }
    }
}

void help(void)
{
    printf("\n\n\t\t\t------Instructions------\t\t\t");
    printf("\n\n\n\t\t\tThis is the pattern of the board\t\t\t");
    printf("\n\n\t\t\t1 2 3\n\t\t\t4 5 6\n\t\t\t7 8 9");
    printf("\n\n\t\t\tPlayer has to put their sign in the empty block \n\t\t\tpositioned by the numbers as shown above!");
    printf("\n\n\t\t\t------Enjoy your game------!!\n\n\n");
}

void insert(char game_board[], char *turnof)
{
    int position;

    printf("your turn %c\n",*turnof);
    //asking user where they want to put their symbol on

    do
    {
        printf("enter where you want to place your play: ");
        scanf("%i", &position);
    }
    while(game_board[position-1]!='_');

    //placing that players symbol in thier prefered space

        game_board[position-1]=*turnof;
    
}

void switch_turn(char *turnof)
{
    //switching the players turn
    if(*turnof=='X')
    {
        *turnof='O';
    }
    else
    {
        *turnof='X';
    }
}

bool win(char game_board[])
{
    bool check = false;

    // checking first row
    if(game_board[0]!='_')
    {
        if(game_board[0]==game_board[1])
        {
            if(game_board[0]==game_board[2])
            {
                check = true;
            }
        }
    }

    //checking second row
    if(game_board[3]!='_')
    {
        if(game_board[3]==game_board[4])
        {
            if(game_board[3]==game_board[5])
            {
                check = true;
            }
        }
    }

    // checking third row
    if(game_board[6]!='_')
    {
        if(game_board[6]==game_board[7])
        {
            if(game_board[6]==game_board[8])
            {
                check = true;
            }
        }
    }

    // checking first column
    if(game_board[0]!='_')
    {
        if(game_board[0]==game_board[3])
        {
            if(game_board[0]==game_board[6])
            {
                check = true;
            }
        }
    }

    //checking second column
    if(game_board[1]!='_')
    {
        if(game_board[1]==game_board[4])
        {
            if(game_board[1]==game_board[7])
            {
                check = true;
            }
        }
    }

    //checking thir column
    if(game_board[2]!='_')
    {
        if(game_board[2]==game_board[5])
        {
            if(game_board[2]==game_board[8])
            {
                check = true;
            }
        }
    }

    //checking first diagonal
    if(game_board[0]!='_')
    {
        if(game_board[0]==game_board[4])
        {
            if(game_board[0]==game_board[8])
            {
                check = true;
            }
        }
    }

    //checking second diagonal
    if(game_board[2]!='_')
    {
        if(game_board[2]==game_board[4])
        {
            if(game_board[2]==game_board[6])
            {
                check = true;
            }
        }
    }
    return check;
}

bool draw(int play_count)
{
    //if all of the boxes are not filled then reuturn false
    if(play_count<9)
    {
        return false;
    }
    //if all of the boxes are filled and still there is no winner reuturn false
    else
    {
        return true;
    }
}

void selfplay()
{
        char turnof = 'X';
    //array of game_board
    char game_board[9] = {'_','_','_','_','_','_','_','_','_'};

    //keeping track of total number of plays
    int play_count=0;
    //assigning playing variable ture variable so that the loop is always continued
    bool playing = true;

    help();

    //the loop continues till one of thw player wins or the game is ended in draw
    while (playing)
    {
        //display the game_board 
        display_board(game_board);
        //ask the turned player to put their symbol
        insert(game_board, &turnof);
        //increase the number of play 
        play_count++;
        //checking if any player has won
           //if any player has won then true bool value is returned from the win function to the main function
                //then if it is true then we enter inside the if condition or else we go to check draw function
        if(win(game_board))  
        {
            display_board(game_board);
            printf("%c Wins!!\n",turnof);
            break;
        }
        //checking for a draw
            //if the game is drawn then true bool value is returned from the draw function to the main function
                //then if it is true then we enter inside the if condition or else we swictch the players play turn
        if(draw(play_count))
        {
            display_board(game_board);
            printf("DRAWWWWW!!\n");
            break;
        }
        //if both the win and draw conditions are not satisfied then the play turn is switched to another player
        switch_turn(&turnof);
    }
}

int main(void)
{   
    int option;
    
    printf("\t\t\n\nWELCOME TO THE TIC TAC TOE GAME MADE USING C PROGRAMMING LANGUAGE!\n\n");
    printf("\t\tHERE THERE ARE TWO GAME MODES\n\n");
    printf("\t\t1)Computer Mode\n\t\t2)Player Mode");
    printf("\t\t\n\nWhich do you prefer: ");
    scanf("%d",&option);
    
    if(option==1)
    {
        printf("\t\t\n\nLet's begin your game with the Computer!");
        printf("\n\n\n\t\tKnow this before hand\n\n\n");
        printf("Horizontal is the ROW ----\n\n\n");
        printf("Vertical is the COLUMN |\n");
        printf("\t\t       |\n\n");
        printf("\t\tYou play first!\n\n");
        printf("\t\tyou are 'X'\n\n");

        compPlay();
    }
    else
    {
        selfplay();
    }
    return 0;
}