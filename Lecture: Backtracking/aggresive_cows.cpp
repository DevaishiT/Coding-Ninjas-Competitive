#include<bits/stdc++.h>
using namespace std;

long long max_mindist(long long arr[], long long n, long long c, long long min, long long max) 
{
  if (n < c) return -1;
  long long mid, count;
  int current;
  bool flag;
  long long ans = 0;
 
  while (max >= min)
  {
      mid = min + (max-min)/2;
      //cout<<mid<<endl;
      count = c;
      current = 0;
      flag = false;

      while(count != 0)
      {
        if (current == n)
        {
          flag = true;
          break;
        }
        int j = 0;
        while(arr[current + j] - arr[current] < mid) j++;
        current = current + j;
        count--;
      }
      if (flag) 
      {
        max = mid - 1;
        //cout<<"y"<<endl;
      }
      else
      {
        if (mid > ans) ans = mid;
        min = mid + 1;
      }
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
        cout<<max_mindist(xi, n, c, 0, xi[n-1]-xi[0])<<endl;
    }
}