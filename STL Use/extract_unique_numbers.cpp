#include<bits/stdc++.h>

using namespace std;

char fin[500000];

char* uniqueChar(char *str){
    // Write your code here
	unordered_set<char> s;
    for(int i=0; str[i] != '\0'; i++) s.insert(str[i]);
    
    int k =0;
    
    for(int i=0; str[i] != '\0'; i++)
    {
        if (s.find(str[i]) != s.end())
        {
            fin[k++] = str[i];
            s.erase(str[i]);
        }
    }
    fin[k] = '\0';
    
    // for(it = s.begin(); it != s.end(); it++) fin[k++] = *it;
    // for(int i=0; fin[i] != '\0'; i++) cout<<fin[i]<<endl;
    // cout<<endl;
    return fin;
}