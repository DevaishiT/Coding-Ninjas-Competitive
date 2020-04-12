#include<bits/stdc++.h>

using namespace std;

bool isPossible(int board[][9], int x, int y, int val)
{
	//row
	for(int i=0; i<9; i++)
	{
		if (i != y && board[x][i] == val)
			return false; 
	}

	//column
	for(int i=0; i<9; i++)
	{
		if (i != x && board[i][y] == val)
			return false; 
	}

	//box
	for(int i= (x - x%3); i < (x - x%3 + 3); i++)
	{
		for(int j= (y - y%3); j < (y - y%3 + 3); j++)
		{
			if (i == x && j == y) continue;
			if (board[i][j] == val) return false;
		}
	}
	return true;
}

bool sudokuHelper(int board[][9], int x, int y)
{
	if (y == 9) return true;
	if (board[x][y] != 0)
	{
		if (x < 8) return sudokuHelper(board, x+1, y);
		else return sudokuHelper(board, 0, y+1);
	}
	bool res;
	for(int i=1; i<=9; i++)
	{
		if (isPossible(board, x, y, i))
		{
			board[x][y] = i;
			if (x < 8) res = sudokuHelper(board, x+1, y);
			else res = sudokuHelper(board, 0, y+1);
			board[x][y] = 0;
			if (res == true) return res;
		}
	}
	return false;
}

bool sudokuSolver(int board[][9])
{
	bool ans = sudokuHelper(board, 0, 0);
  	return ans;
}
