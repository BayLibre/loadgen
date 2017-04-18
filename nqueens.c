/*
 * N-Queens Problem Solver
 * Found somewhere on the Internet; can't remember where. Possibly Wikipedia.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static inline int __abs(int n)
{ 
	return n > 0 ? n : -n;
}

static int place(int row, int column, int board[])
{
	int i;
	for(i = 1; i <= row - 1; ++i) {
		if(board[i] == column)
			return 0;
		else if(__abs(board[i] - column) == __abs(i - row))
			return 0;
	}
	return 1;
}

void nqueens(int row, int n, int board[])
{
	int column;

	if (row == 0)
		for(column = 0; column < n; column++)
				board[column] = 0;
	for(column = 1; column <= n; ++column) {
		if(place(row, column, board)) {
			board[row] = column;
			if(row == n)
				break;
			else
				nqueens(row + 1, n, board);
		}
	}
}
