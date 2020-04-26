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

long long int mixture(vector<int>arr, int **dp, int i, int j)
{
	if(i == j)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	long long int minCost = INT_MAX;
	int left_sum = 0;
	int right_sum = 0;

	for(int k=i;k<=j;k++)
	{
		right_sum += arr[k];
		right_sum %= 100;
	}

	for(int k=i;k<j;k++)
	{
		left_sum = (left_sum + arr[k])%100;
		right_sum = (right_sum - arr[k] + 100)%100;
		long long int possibleAns = mixture(arr,dp,i,k) + mixture(arr,dp,k+1,j) + 
							left_sum*right_sum;

		if(possibleAns < minCost)
			minCost = possibleAns;
	}

	dp[i][j] = minCost;
	return minCost;
}

/*int mcm(int* p, int n)
{
	int **dp = new int*[n+1];

	for (int i = 0; i <n+1; i++)
		dp[i] = new int[n+1];

	for (int i = 0; i < n+1; i++)
		for (int j = 0; j < n+1; j++)
			dp[i][j] = -1;
  
 	return matrixMultiply(p,dp,1,n);

}*/

int solve(int n, vector<int> colors)
{
	int **dp = new int*[n];

	for (int i = 0; i <n; i++)
		dp[i] = new int[n+1];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dp[i][j] = -1;
  
 	return mixture(colors, dp, 0, n-1);
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++)
		cin >> arr[i];
	cout << solve(n, arr) << endl;
}