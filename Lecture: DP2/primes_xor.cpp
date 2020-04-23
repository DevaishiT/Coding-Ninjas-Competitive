#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

bool sieve[9000];
int dp[1001][8193];

void make_sieve()
{
    sieve[0] = false;
    sieve[1] = false;
    for(int i = 2; i < 9000 ; i++)
        sieve[i] = true;

    for(int i = 2; i*i < 9000; i++)
    {
        if(sieve[i])
        {
            for(int j = i*i; j < 9000; j += i)
                sieve[j] = false;
        }
    }
    return ;
}

int solver( vector<int> &v)
{
    // storing count of all values
    vector<unsigned short int> count(1001, 0);
    for(int i=0; i<v.size(); i++)
        count[v[i] - 3500]++;

    // storing unique values
    vector<int> unique;
    for(int i=0; i<=1000; i++)
        if (count[i] != 0) 
            unique.push_back(i + 3500);

    int s = unique.size();
    memset(dp, 0, sizeof(dp));
 
    // using bottom up to find ways
    dp[0][0] = 1;
    int n;
    for(int i=1; i<=s; i++)
    {
        for(int j=0; j<= 8192; j++)
        {
            n = count[unique[i-1] - 3500];
            dp[i][j] = ((dp[i-1][j]*(1 + (n/2)))%mod + 
            (dp[i-1][j^unique[i-1]]*((n+1)/2))%mod)%mod;
        }
    }

    int ways = 0;
    for(int i=0; i<8193; i++)
    {
        if (dp[s][i] != 0)
        {
            if (sieve[i])
                ways = (ways + dp[s][i])%mod;
        }
    }

    return ways;
}

int main()
{
    int t;
    cin >> t;
    make_sieve();
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        int temp;
        for(int i=0; i<n ;i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        cout << solver(v) << endl;
    }
    return 0;
}
