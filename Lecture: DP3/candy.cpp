long long solve(int like[][MAXN],int n)
{
	int size = pow(2,n);
	long long dp[size] = {0};
	dp[size - 1] = 1;
	for(int mask = size-2; mask >= 0; mask--)
	{
		int y = 0;
		for(int i=0; i<n; i++)
        {
            if ((mask & (1<<i)) != 0) y++;
        }
        //cout << y << endl;
		for(int j=0; j<n; j++)
		{
			if (like[y][j] == 1 && (mask & (1<<j)) == 0)
				dp[mask] += dp[mask|(1<<j)];
		}
	}
	return dp[0];
}