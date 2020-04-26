//partially correct

#include<bits/stdc++.h>
using namespace std;

int count_set_bits(int n, int x)
{
    int num = 0;

    for(int i=0;i<n;i++)
        if( (x&(1<<i)) != 0)
            num++;

    return num;
}

int rec_solver(vector<vector<int>> &dp, int mask, int pos, vector<string> &v, int n)
{
    int y = count_set_bits(n,mask);

    // the two bases cases
    if (y == 1) return 0;
    if (pos == n || y == 0) return 100000;
    
    // in case of overlapping 
    if (dp[mask][pos] != -1) 
        return dp[mask][pos];
    
    int mask1 = mask;
    int mask2 = mask;
    for(int i=0; i<n; i++)
    {
        if ((mask & (1<<i)) != 0)
        {
            if (v[i][pos] == '1')
            {
                mask1 = (mask1 & ~(1<<i));
            }
            else mask2 = (mask2 & ~(1<<i));
        }
    }
    
    //cout << mask << " " << mask1 << " " << mask2 << endl;

    int val = min(rec_solver(dp,mask1,pos+1,v,n) + rec_solver(dp,mask2,pos+1,v,n) + y
              , rec_solver(dp,mask,pos+1,v,n));
    
    dp[mask][pos] = val;
    return val;
}

int minimumTouchesRequired(int n, vector<string> v) {
    /* Don't write main().
     * Don't read input, they are passed as function arguments.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int len = v[0].length();
    int size = pow(2,n);
    vector<vector<int>> dp(size, vector<int>(len,-1));
    size--;
    return rec_solver(dp, size, 0, v, n);
}