#include <bits/stdc++.h>
using namespace std;

int getCodes(string input, string output[10000]) {
    map<string, char> m;
    
    char ch = 'a';
    for(int i=1; i<=26; i++)
        m[to_string(i)] = ch++;
    
    if (input == "")
    {
        output[0] = "";
        return 1;
    }
    
    int smalloutput = getCodes(input.substr(1), output);
    int smalloutput2 = 0;
    if (input.length() >= 2 && stoi(input.substr(0,2)) <= 26)
    	smalloutput2 = getCodes(input.substr(2), output + smalloutput);
    
    int size = smalloutput + smalloutput2;
    for(int i=0; i<smalloutput; i++)
        output[i] = m[input.substr(0,1)] + output[i];
    
    for(int i=smalloutput; i<size; i++)
        output[i] = m[input.substr(0,2)] + output[i];
    
    return size;
}

