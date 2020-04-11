#include<bits/stdc++.h>
using namespace std;

int max_mindist(int arr[], int n, int c, int min, int max) 
{
  if (n < c) return -1;
  int mid, count, current;
  bool flag;
  int ans = 0;
  int print = 0;
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

int main() 
{
  int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        int n, c;
        cin >> n >> c;
        int arr[n];
        for(int j=0; j<n; j++)
            cin >> arr[j];
        sort(arr,arr+n);
        cout<<endl<<max_mindist(arr, n, c, 0, arr[n-1]-arr[0])<<endl;
    }
}