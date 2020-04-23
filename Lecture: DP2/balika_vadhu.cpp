#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2)
{

  int n = s1.length();
  int m = s2.length();
  
    int d[n+1][m+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i == 0 or j == 0)
            {
                d[i][j] = 0;
                continue;
            }

            if(s1[i - 1] == s2[j - 1])
                d[i][j] = d[i-1][j-1] + 1;
            else
            {
                d[i][j] = max(d[i][j-1], d[i-1][j]);
            }
        }
    }
  return d[n][m];
}


int solver(string s1, string s2, int k)
{
  int n = s1.length();
  int m = s2.length();

  int d[n+1][m+1][k+1];
  for(int i=0; i<=n; i++)
  {
    for(int j=0; j<=m; j++)
    {
      for(int l=0; l<=k; l++)
      {
         if(i == 0 or j == 0 or l == 0)
        {
          d[i][j][l] = 0;
          continue;
        }

        if(s1[i - 1] == s2[j - 1])
        {
          d[i][j][l] = d[i-1][j-1][l-1] + s1[i-1];
          int temp = max(d[i-1][j][l], d[i][j-1][l]);
          d[i][j][l] = max(d[i][j][l], temp);
        }
        else
        {
          d[i][j][l] = max(d[i][j-1][l], d[i-1][j][l]);
        }
      }
    }
  }
  if (lcs(s1, s2) >= k) return d[n][m][k];
  else return 0;
}

int main ()
{
  int t;
  cin >> t;
  int k;
  string s1, s2;
  vector<int> v;
  while(t--)
  {
    cin >> s1 >> s2;
    cin >> k;
    v.push_back(solver(s1, s2, k));
  }
  for(int a=0; a<v.size(); a++) cout << v[a] << endl;
  return 0;
}
