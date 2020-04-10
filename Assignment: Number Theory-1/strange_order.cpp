#include<bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
    if (x < y) swap(x,y);
    if (y == 0) return x;
    return gcd(y, x%y);
}

int main() 
{
    int n;
    cin >> n;
    
    set<int> p;
    vector<int> a;
    for(int i=0; i<n; i++) p.insert(i);
    
    set<int>::iterator it = p.end();
    int size = p.size();
    while(size)
    {
        int temp = *it;
        it--;
        p.erase(temp);
        size--;
        a.push_back(temp);
        cout<<p.size()<<endl;
        int v;
        for(; it != p.begin(); it--)
        {
			if (gcd(*it,temp) != 1)
            {
                v = *it;
                it--;
                p.erase(v);
                size--;
                a.push_back(v);
            }
        }
        it = p.end();
    }
    for(int i=0; i<a.size(); i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
    
}