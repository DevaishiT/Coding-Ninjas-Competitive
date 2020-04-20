#include<bits/stdc++.h>

using namespace std;

long long int mod_power(long long int n, long long int m, long long int p) //(n^m) mod p
{
	if (m == 1) return n;
	if (m == 0) return 1;
	long long int temp = (n*n)%p;
	if (m % 2 != 0)
		return (n * mod_power(temp, m/2, p))%p;
	else return mod_power(temp, m/2, p)%p;
}

long long int solver(long long int n, long long int p)
{
	if (n >= p) return 0;
	if (n == 1) return 1;
	long long int temp = 1;
	for(long long int i= n+1; i < p; i++)
	{
		//int mid = mod_power(i, p-1, p);
		//cout << mid << endl;
		temp = (temp * i)%p;
	}
	long long int a = mod_power(temp, p-2, p);
	//cout << a << endl << endl;
	return (-1*a + p)%p;
}

int main ()
{
	int t;
	cin >> t;
	long long int p, n;
	while(t--)
	{
		cin >> n >> p;
		cout << solver(n,p) << endl;
	}
	return 0;
}
