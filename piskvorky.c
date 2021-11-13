#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define MAX_PLAYERS 2
#define MAX_PLAYER_NAME_LENGTH 100

typedef struct player
	{
		char name[MAX_PLAYER_NAME_LENGTH];
		char symbol;
	} player_t;

void getPlayerInfo(player_t players[])
{
	for(int i = 0; i < MAX_PLAYERS; i++)
	{
	printf("Enter player %d name:\n", i + 1);
	scanf("%sMAX_PLAYER_NAME_LENGTH", players[i].name);
	printf("Enter player %d symbol:\n", i + 1);
	scanf(" %c", &players[i].symbol);
	}
}

void initBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
	for(int i = 0; i < BOARD_SIZE; i++)
	{
		for(int j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
	/*       1   2   3
	 *     1   |   |  
	 *	---+---+---
	 *     2   |   |  
	 *	---+---+---
	 *     3   |   |  
	*/

	//prints the helper-numbers above
	printf("  ");
	for(int i = 0; i < BOARD_SIZE; i++)
	{
		printf("%d   ", i + 1);
	}
	printf("\n");

	for(int i = 0; i < BOARD_SIZE; i++)
	{
		//prints the helper number at the beginning of each row
		printf("%d", i + 1);

		//prints the lines with player symbols
		for(int j = 0; j < BOARD_SIZE; j++)
		{
			if( j == BOARD_SIZE - 1)
				printf(" %c \n", board[i][j]);
			else
				printf(" %c |", board[i][j]);
		}

		//doesnt print the spacer line after last symbol line
		if(i == BOARD_SIZE - 1)
			break;
	
		//prints space char so the spacer lines are in line
		printf(" ");

		//print the spacer lines
		for(int j = 0; j < BOARD_SIZE; j++)
		{
			if( j == BOARD_SIZE - 1)
				printf("---\n");	
			else
				printf("---+");
		}
	
	}
	
}

void makeMove(char board[BOARD_SIZE][BOARD_SIZE], player_t player)
{
	system("clear");
	printBoard(board);
	printf("%s's move: enter the number of line and column which you want to take\n", player.name);

	int xPos, yPos;
	scanf("%d %d", &xPos, &yPos);
        xPos--;
        yPos--;
        board[xPos][yPos] = player.symbol;
}

int main()
{
	char board[BOARD_SIZE][BOARD_SIZE];
	player_t players[MAX_PLAYERS];

	getPlayerInfo(players);
	printf("Player one name: %s\nPlayer two name: %s\n", players[0].name, players[1].name);
	printf("Player one symbol: %c\nPlayer two symbol: %c\n", players[0].symbol, players[1].symbol);
	
	initBoard(board);
	printBoard(board);

	makeMove(board, players[0]);
	printBoard(board);

	return 0;
}
