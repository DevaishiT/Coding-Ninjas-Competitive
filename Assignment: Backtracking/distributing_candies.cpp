#include<bits/stdc++.h>
using namespace std;

bool checkPlacable(long long arr[], long long n, long long c, long long d)
{
  if (d == 0) return true;
  long long count = c;
  for(long long i=0; i<n; i++)
  {
    count -= arr[i]/d;
    if (count <= 0) return true;
  }
  return false;
}

long long candies(long long arr[], long long n, long long c, long long min, long long max) 
{
  long long mid;
  long long ans = 0;
 
  while (max >= min)
  {
      mid = min + (max-min)/2;
      
      if (checkPlacable(arr, n, c, mid)) 
      {
        ans = mid;
        min = mid + 1;
      }
      else max = mid - 1;
  }
  return ans;
}


int main() {

    long long t;
    cin>>t;
    
    for(long long t0=0;t0<t;t0++)
    {
        long long n,c,i;
        cin>>n>>c;
        
        long long xi[n];

        for(i=0;i<n;i++)
            cin>>xi[i];

        sort(xi,xi+n);
        cout<<candies(xi, n, c, 0, xi[n-1])<<endl;
    }
}