#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli gcd(lli a, lli b)
{
	if (a < b) swap(a,b);
	if(b == 0) return a;

	return gcd(b,a%b);
}

void func(lli n)
{
	lli sum = n;
	for(lli i = 2; i <= n; i++)
	{
		lli product = n*i;
		sum += product/gcd(n,i);
	}
	cout << sum << endl;
}

