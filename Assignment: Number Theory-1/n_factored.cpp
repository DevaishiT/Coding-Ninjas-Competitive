#include<bits/stdc++.h>

using namespace std;

vector<int> primes_n (int n)
{
	vector<bool> arr(n+1, true);
	vector<int> primes;
	arr[0] = false;
	arr[1] = false;

	int k = int(sqrt(n));
	for(int i=0; i <= k; i++ )
	{
		if (arr[i] == false) continue;
		for(int j = 2*i; j <= n; j += i) arr[j] = false;
	}

	int count = 0;
	for(int i=0; i<=n; i++)
		if (arr[i] == true) primes.push_back(i);
	
	return primes;
}

vector<int> precompute()
{
	vector<int> ans(1000001, 0);
	vector<int> primes = primes_n(1000000);

	for(int i=0; i<primes.size(); i++)
	{
		int temp = primes[i];
		while(temp <= 1000000)
		{
			ans[temp]++;
			temp += primes[i];
		}
	}

	return ans;
}

int main ()
{
	int t;
	cin >> t;
	
	vector<int> ans = precompute();
	for(int j=0; j<t; j++)
	{
		int a, b, n;
		cin >> a >> b >> n;
		int count = 0;
		for(int i=a; i<=b; i++)
			if (ans[i] == n) count++;
		cout<<count<<endl;
	}

	return 0;
}