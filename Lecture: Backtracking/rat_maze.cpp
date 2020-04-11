#include<bits/stdc++.h>

using namespace std;

bool path[21][21];

void mazehelper(int maze[][20], int n, int x, int y)
{
	if (x == n-1 && y == n-1)
	{
		path[x][y] = true;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				cout<<path[i][j]<<" ";
		}
		cout<<endl;
		path[x][y] = false;
		return;
	}

	//left
	if (x > 0 && maze[x-1][y] == 1 && path[x-1][y] == false)
	{
		path[x][y] = true;
		mazehelper(maze, n, x-1, y);
		path[x][y] = false;
	}

	//right
	if (x < n-1 && maze[x+1][y] == 1 && path[x+1][y] == false)
	{
		path[x][y] = true;
		mazehelper(maze, n, x+1, y);
		path[x][y] = false;
	}

	//up
	if (y > 0 && maze[x][y-1] == 1 && path[x][y-1] == false)
	{
		path[x][y] = true;
		mazehelper(maze, n, x, y-1);
		path[x][y] = false;
	}

	//down
	if (y < n-1 && maze[x][y+1] == 1 && path[x][y+1] == false)
	{
		path[x][y] = true;
		mazehelper(maze, n, x, y+1);
		path[x][y] = false;
	}
	
	return;
}

void ratInAMaze(int maze[][20], int n)
{
	memset(path,false,21*21);
	mazehelper(maze, n, 0, 0);
	return;
}
