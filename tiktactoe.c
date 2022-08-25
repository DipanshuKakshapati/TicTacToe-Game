#include <stdio.h>

void display_board(char game_board[])
{
    int i;
    for(i=0;i<9;i++)
    {
        printf("%c ",game_board[i]);
     
        if((i+1)%3==0)
        {
            printf("\n");
        }
    }
}

void display_turn(char *turnof)                 
{
    printf("%c\n",*turnof);
}

void insert(char game_board[], char *turnof)
{
    int position;

    printf("your turn %c\n",*turnof);
    printf("enter where you want to place your play: ");
    scanf("%i", &position);
    game_board[position-1]=*turnof;
}

void switch_turn(char *turnof)
{
    if(*turnof=='X')
    {
        *turnof='O';
    }
    else
    {
        *turnof='X';
    }
}

int main(void)
{
    char turnof = 'X';
    char game_board[9] = {'_','_','_','_','_','_','_','_','_'};

    display_board(game_board);
    printf("\n");
    display_turn(&turnof);
    insert(game_board, &turnof);

    display_board(game_board);

    printf("\n");
    switch_turn(&turnof);
    display_turn(&turnof);
    insert(game_board, &turnof);
    display_board(game_board);
    printf("\n");

}












