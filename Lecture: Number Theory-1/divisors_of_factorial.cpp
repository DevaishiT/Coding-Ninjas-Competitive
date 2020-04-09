#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long int lli;

lli num_divisors(int n)
{
	vector<bool> arr(n+1, true);
	arr[0] = false;
	arr[1] = false;

	int k = int(sqrt(n));
	for(int i=0; i <= k; i++ )
	{
		if (arr[i] == false) continue;
		for(int j = 2*i; j <= n; j += i) arr[j] = false;
	}

	lli count = 1;
	int num;
	int sum;
	for(int i=0; i<=n; i++)
	{
		if (arr[i] == true)
		{
			sum = 0;
			for(int j=i; j <= n; j*= i) sum += n/j;
			count = (count*(sum + 1))%MOD;
		}
	}
	return count%MOD;
}

int main ()
{
	int t,n;
	cin >> t;

	for(int i=0; i<t; i++)
	{
		cin >> n;
		if(n == 0 || n == 1)
		{
			cout << 1 << endl;
			continue;
		}
		cout << num_divisors(n) << endl;
	}
	return 0;
}
