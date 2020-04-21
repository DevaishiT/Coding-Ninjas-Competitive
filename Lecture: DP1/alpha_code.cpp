#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int alpha_code(int * input, int size) {
    vector<int> output(size + 1,0);
    output[0] = 1;
    output[1] = 1;

    for (int i = 2; i <= size; i++) {
        if (input[i-1] != 0)
        {
            output[i] = output[i - 1] % mod;
        }
    
        if (input[i-2] *10 + input[i - 1] <= 26)
        {
            if (input[i-2] != 0)
            {
                output[i] = (output[i - 2] + output[i])%mod;
            }
        }
    }
    int ans = output[size];
    return ans;
}

int main()
{
    string input;
    while(1)
    {
        cin >> input;
        if(input[0] == '0') return 0;
        int len = input.length();
        int arr[len];
        for(int i=0; i<len; i++)
            arr[i] = input[i] - 48;
        cout << alpha_code(arr,len) << endl;
    }
    return 0 ; 
}