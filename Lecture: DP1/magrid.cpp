#include <bits/stdc++.h>
using namespace std;

int solver( vector<vector<int>> input, int r, int c)
{
	vector<vector<int>> dp(r, vector<int> (c,0));
	dp[r-1][c-1] = 1;

	for (int i = r - 2; i >= 0; i--) 
	{
		dp[i][c - 1] = dp[i + 1][c - 1] - input[i][c - 1];
		if (dp[i][c - 1] < 1) dp[i][c - 1] = 1;
	}

	for (int j = c - 2; j >=0; j--) {
		dp[r -1][j] = dp[r - 1][j + 1] - input[r - 1][j];
		if (dp[r -1][j] < 1) dp[r -1][j] = 1;
	}

	for (int i = r - 2; i >=0; i--) 
	{
		for (int j = c - 2; j >=0 ; j--) 
		{
			dp[i][j] = min(dp[i+1][j], dp[i][j + 1]) - input[i][j];
			if (dp[i][j] < 1) dp[i][j] = 1;
		}
	}

	return dp[0][0];
}

int main() 
{
	int t;
	cin >> t;
	while (t--)
	{
		int r, c;
		cin >> r >> c;
		vector<vector<int>> arr(r, vector<int> (c,0));
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				cin >> arr[i][j];
		cout << solver(arr, r, c) << endl;
	}
	return 0;
}