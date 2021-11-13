#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define MAX_PLAYERS 4
#define MAX_PLAYER_NAME_LENGTH 100

typedef struct player
	{
		char name[MAX_PLAYER_NAME_LENGTH];
		char symbol;
	} player_t;

void takeBoardPosition(char board[BOARD_SIZE][BOARD_SIZE], char* player, int xPos, int yPos)
{
	
}

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

void printBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
	/*	 X | O | X
	 *	---+---+---
	 *	 O | X | O
	 *	---+---+---
	 *	 O | X | O
	*/

	for(int i = 0; i < BOARD_SIZE; i++)
	{
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

int main()
{
	char board[BOARD_SIZE][BOARD_SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
	player_t players[MAX_PLAYERS];

	//getPlayerInfo(players);
	//printf("Player one name: %s\nPlayer two name: %s\n", players[0].name, players[1].name);
	//printf("Player one symbol: %c\nPlayer two symbol: %c\n", players[0].symbol, players[1].symbol);
	
	printBoard(board);
	
	return 0;
}
