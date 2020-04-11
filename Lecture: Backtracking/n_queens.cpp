#include<bits/stdc++.h>

using namespace std;

bool chess[11][11];

bool isPossible(int n, int row, int col)
{
	for(int i = row-1; i >= 0; i--)
		if (chess[i][col] == true) return false;

	for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
		if (chess[i][j] == true) return false;

	for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
		if (chess[i][j] == true) return false;

	return true;
}

void nQueenhelper(int n, int row)
{
	if (row == n)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				cout<<chess[i][j]<<" ";
		}
		cout<<endl;
		return;
	}

	for(int i=0; i<n; i++)
	{
		if (isPossible(n,row,i))
		{
			chess[row][i] = true;
			nQueenhelper(n,row + 1);
			chess[row][i] = false;
		}
	}

	return;
}

void placeNQueens(int n)
{
	memset(chess,false,11*11);
	nQueenhelper(n, 0);
	return;
}

int main()
{
	int n;
	cin >> n;
	placeNQueens(n);
}