#include<bits/stdc++.h>
using namespace std;

int knapsack(int* weights, int* values, int n, int maxWeight)
{
  int w = maxWeight;
  vector<vector<int>> dp(w+1,vector<int>(n+1,0));
    
  for(int i=0; i<=w; i++)
  {
    for(int j=0; j<=n; j++)
    {
      if (i == 0 or j == 0)
      {
           dp[i][j] = 0;
          continue;
      }

      dp[i][j] = dp[i][j-1];
      if (i >= weights[j-1])
        dp[i][j] = max(dp[i][j], (values[j-1] + dp[i - weights[j-1]][j-1]));
    }
  }
  return dp[w][n];
}

int knapsack(int* weights, int* values, int n, int maxWeight)
{
  int w = maxWeight;
  vector<vector<int>> dp(w+1,vector<int>(2,0));
    
  for(int j=0; j<n; j++)
  {
    if (j % 2 == 0)
    {
        for(int i=1; i<=w; i++)
        {
          if (i >= weights[j])
            dp[i][0] = max(dp[i][1], (values[j] + dp[i - weights[j]][1]));
          else dp[i][0] = dp[i][1];
        }
    }
    else
    {
        for(int i=1; i<=w; i++)
        {
          if (i >= weights[j])
            dp[i][1] = max(dp[i][0], (values[j] + dp[i - weights[j]][0]));
          else dp[i][1] = dp[i][0];
        }
    }
  }
  return (n%2 != 0) ? dp[w][0] : dp[w][1];
}