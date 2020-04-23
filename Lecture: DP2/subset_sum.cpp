
#include<bits/stdc++.h>
using namespace std;

bool subset_sum(int n, int* input, int k)
{
  vector<vector<bool>> dp(n+1,vector<bool>(k+1,false));
  //vector<bool> taken(n, false); 
  for(int i=0; i<=n; i++) dp[i][0] = true;
    
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=k; j++)
    {
      if (j >= input[i-1])
        dp[i][j] = dp[i-1][j] or dp[i-1][j-input[i-1]];
      else dp[i][j] = dp[i-1][j];
    }
  }

  for(int i=0; i<=n; i++)
  {
  	for(int j=0; j<=k; j++)
  		cout << dp[i][j] << " ";
  	cout << endl;
  }

  return dp[n][k];
}

int main()
{
	int n;
	cin >> n;

	int *input = new int[n];
	for(int i=0;i<n;i++) cin >> input[i];

	int k;
	cin >> k;

	if(subset_sum(n, input, k))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;	

	return 0 ; 

}

