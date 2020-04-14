#include <bits/stdc++.h>
using namespace std;

int alpha_code(string input) 
{
    int val = 0;
    int m = 1000000007;
    
    if (input.length() == 0) return 1;
    if (input[0] == '0') return 0;
    
    val = (val + alpha_code(input.substr(1))%m)%m;
    
    if (input.length() >= 2 && stoi(input.substr(0,2)) <= 26)
        val = (val + alpha_code(input.substr(2))%m)%m;
    
    return val;
}

int main()
{
    string input;
    while(1)
    {
        cin >> input;
        if(input[0] == '0') return 0;
        cout << alpha_code(input) << endl;
    }
    return 0 ; 
}