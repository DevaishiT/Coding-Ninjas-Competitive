#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

vector<int> primes_n (int n)
{
	vector<bool> arr(n+1, true);
	vector<int> primes;
	arr[0] = false;
	arr[1] = false;

	int k = int(sqrt(n));
	for(int i=2; i <= k; i++ )
	{
		if (arr[i] == false) continue;
		for(int j = i*i; j <= n; j += i) arr[j] = false;
	}

	int count = 0;
	for(int i=0; i<=n; i++)
		if (arr[i] == true) primes.push_back(i);
	
	return primes;
}

void primes_lr(lli l, lli r, vector<int> &primes)
{ 
    vector<bool> sieve(r-l+1, true);
   
    int temp;
    lli start;
	for(int i=0; primes[i] <= sqrt(r); i++ )
	{
		//if (primes[i] > sqrt(r)) break;
        temp = primes[i];
        
        if (l % temp == 0) start = l;
        else start = (l/temp)*temp + temp;

		for(lli j = start; j <= r; j += temp)
            sieve[j - l] = false;

        if(start == temp)
            isPrime[start - l] = true;
	}
    
	for(int i = 0; i < sieve.size(); i++)
		if (sieve[i] == true) cout << l+i << endl;
	
	return;
}

int main()
{
	// Write your code here
    int t;
    cin >> t;
    vector<int> primes = primes_n(1000000);
    while(t--)
    {
    	lli l,r;
        cin >> l >> r;
        primes_lr(l, r, primes);
    }
	return 0;
}
