#include<bits/stdc++.h>

#define mod 1000000007

using namespace std;

long long solver ( int arr[], int count[], int n)
{
    sort(arr, arr+n);
    for(int i=0; i<n; i++) count[i] = 1;
    
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if (arr[i] % arr[j] == 0)
                count[i] = (count[i] + count[j])%mod;
        }
    }
    int sum = 0;
    for(int i=0; i<n; i++) sum = (sum + count[i])%mod;
    return sum;
}

long long solver2 ( int arr[], int count[], int n)
{
    long long sum = 0;
    
    sort(arr,arr +n);
    int max = arr[n-1];
    for(int i=0; i<n; i++) count[arr[i]] = 1;
    for(int i=0; i<=max; i++)
    {
        if (count[i] == 0) continue;
        for(int j=2*i; j<=max; j += i)
        {
            if (count[j] == 0) continue;
            count[j] = (count[j] + count[i])%mod;
        }
    }
    for(int i=0; i<n; i++)
    {
        sum = (sum + count[arr[i]])%mod;
        count[arr[i]] = 0;
    }
    return sum%mod;
}

int main(){
	// Write your code here
    int t;
    cin >> t;
    int count[750001] = {0};
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++) cin >> a[i];
        cout << solver2(a, count, n) << endl;
    }
	return 0;
}