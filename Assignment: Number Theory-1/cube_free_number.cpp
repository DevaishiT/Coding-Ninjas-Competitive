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

vector<pair<bool,int>> solver (int max)
{
	vector<pair<bool,int>> v (max + 1, make_pair(true,-1));
	int x = int( cbrt(max));
	vector<int> primes = primes_n(x);
	int div;
	for(int i=0; i<primes.size(); i++)
	{
		div = pow(primes[i], 3);
		int temp = div;
		while(temp <= max)
		{
			if (v[temp].first == true) v[temp].first = false;
			temp += div;
		}
	}
	int k = 0;
	for(int i=0; i<=max; i++)
	{
		if (v[i].first == true)
			v[i].second = k++;
	}

	return v;
}

int main ()
{
	int t;
	cin >> t;
	vector<int> testcases(t);
	int max = INT_MIN;
	for(int b=0; b<t; b++)
	{
		cin >> testcases[b];
		if (testcases[b] > max)
			max = testcases[b];
	}
	vector<pair<bool,int>> arr = solver(max);
	for(int b=0; b<t; b++)
	{
		cout<<"Case "<<b+1<<": ";
		if (arr[testcases[b]].first == true) 
			cout<<arr[testcases[b]].second<<endl;
		else cout<<"Not Cube Free"<<endl;
	}
	return 0;
}