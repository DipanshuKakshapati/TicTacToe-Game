#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
    printf("enter where you want to place your play: ");
    scanf("%i", &position);
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

int main(void)
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












