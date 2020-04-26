#include<bits/stdc++.h>

using namespace std;

int matrixMultiply(int*arr, int **dp, int i, int j)
{
	if(i == j)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	int minCost = INT_MAX;
	for(int k=i;k<j;k++)
	{
		int possibleAns = matrixMultiply(arr,dp,i,k) + matrixMultiply(arr,dp,k+1,j) + 
							arr[i-1]*arr[k]*arr[j];

		if(possibleAns < minCost)
			minCost = possibleAns;
	}

	dp[i][j] = minCost;
	return minCost;
}

int mcm(int* p, int n)
{
	int **dp = new int*[n+1];

	for (int i = 0; i <n+1; i++)
		dp[i] = new int[n+1];

	for (int i = 0; i < n+1; i++)
		for (int j = 0; j < n+1; j++)
			dp[i][j] = -1;
  
 	return matrixMultiply(p,dp,1,n);

}
