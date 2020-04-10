#include <bits/stdc++.h>
using namespace std;

int returnPermutations(string input, string output[])
{
    if (input == "")
    {
        output[0] = "";
        return 1;
    }
    string dupl[1000];
    int smalloutput = returnPermutations(input.substr(1), dupl);
    //cout<<smalloutput<<endl;
    int len = dupl[0].length() + 1;
    for(int i=0; i<smalloutput; i++)
    {
        for(int j=0; j<len; j++)
            output[i*len + j] = dupl[i].substr(0,j) + input.substr(0,1) + dupl[i].substr(j);
    }
    
    return len*smalloutput;
}
