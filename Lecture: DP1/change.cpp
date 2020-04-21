#include<bits/stdc++.h>
using namespace std;

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
  
  int k = numDenominations;
  int n = value;
    
  vector<vector<int>> ways(k + 1, vector<int> (n + 1, 0));
    
  for(int i=0; i<=k; i++) ways[i][0] = 1;

  for(int i=1; i<=k; i++)
  {
    for(int j=1; j<=n; j++)
    {
      ways[i][j] = ways[i-1][j];
      if (j >= denominations[i-1]) 
        ways[i][j] += ways[i][j - denominations[i-1]]; 
    }
  }

  return ways[k][n];
}

int main()
{
  int k;
  cin >> k;
  int arr[k];
  for(int i=0; i<k; i++) cin >> arr[i];
  int n;
  cin >> n;
  cout << countWaysToMakeChange(arr,k,n) << endl;
  return 0;
}
