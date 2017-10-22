/*
	Two players console program for a Tic Tac Toe game
	by: Thang Q. Phu
*/

#include <stdio.h>

int winner(char board[3][3]);
void draw_board(char board[3][3]);

int main() 
{	
	int rounds = 1;
	int position, player, row, col;
	char mark, c;
	printf("Two players Tic Tac Toe game\n");
	char board[3][3] = {
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'}	
	};
	draw_board(board);	
	while(rounds <= 9 && !winner(board)) {
		player = (rounds % 2) ? 1 : 2;
		mark = (player == 1) ? 'X' : 'O';
		printf("Player %d select a position from 1 to 9: ", player);
		scanf("%d", &position);
		row = (position - 1) / 3;
		col = (position - 1) % 3;
		if(board[row][col] != 'X' && board[row][col] != 'O' && position > 0 && position < 10) { // check valid inputs
			board[row][col] = mark;
			draw_board(board);
			if(winner(board)) {
				printf("*~*~* Congratulations Player %d. You win! *~*~*\n", player);
				break;
			}
			rounds++;
		} else {
			printf("Invalid position try again. ");
		}
	}
	if(rounds > 9) {
		printf("Good game players. It was a draw game\n");
	}
	
	return 0;	
}

/*
	take in the current stage of the board matrix as parameter
	draw the board
*/
void draw_board(char board[3][3]) 
{
	int i;
	for(i = 0; i < 3; i++) {
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if(i != 2) {
			printf("---|---|---\n");
		}
	}
}


/*
	take in the current stage of the board matrix as parameter
	return 1 if there has been a winner, otherwise return 0
*/
int winner(char board[3][3]) {
	int i;
	for(i = 0; i < 3; i++) {
		if((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
			(board[0][i] == board[1][i] && board[1][i] == board[2][i])) { // row or column wins
			return 1;
		}
	}

	if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || 
		(board[0][2] == board[1][1] && board[1][1] == board[2][0])) { // diagonal wins
		return 1;
	}	
	return 0;
}
