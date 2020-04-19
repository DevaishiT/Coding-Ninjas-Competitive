#include<bits/stdc++.h>

using namespace std;
#define MAX 2000001

int gcd(int a,int b)
{
    if(a < b) swap(a,b);
    if(b == 0) return a;
    else return gcd(b,a%b);
}

vector<bool> create_sieve( int n)
{
    vector<bool> sieve(n+1, false);

    for(int i = 2; i <= n; i++)   
        sieve[i] = true;
    
    for(int i = 2; i <= sqrt(n);i++)
    {
        if(sieve[i])
        {
            for(int j = 2*i; j <= n ;j += i)
                sieve[j] = false;
        }
    }
    return sieve;
}

int main()
{
    int n;
    cin >> n;

    vector<bool> sieve = create_sieve(n);
    
    vector<int> out;
    set<int> removed;

    int temp = n;
    while( temp != 0)
    {
        if(removed.find(temp) == removed.end())
        {
            if(sieve[temp])
            {
                out.push_back(temp);
                removed.insert(temp);
            }
            else
            {
                out.push_back(temp);
                for(int i = temp-1; i >1 ; i--)
                {
                    if(gcd(temp,i)!=1)
                    {
                        if(removed.find(i) == removed.end() )
                        {
                            out.push_back(i);
                            removed.insert(i);
                        }
                        
                    }
                }
            }
        }
        temp--;
    }
    for(int i = 0; i< n; i++)
        cout<<out[i]<<" ";
    cout<<endl;
    return 0;
}