#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef long long int lli;

lli solver(int * input, int size) {
    vector<lli> output(size + 1,0);
    output[0] = 0;
    output[1] = input[0];

    for (int i = 2; i <= size; i++) 
    {
        output[i] = max(output[i-1], output[i-2] + input[i-1]);
    }
    lli ans = output[size];
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for(int q=1; q<=t; q++)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];
        cout << "Case " << q <<": ";
        cout << solver(arr,n) << endl;
    }
    return 0 ; 
}