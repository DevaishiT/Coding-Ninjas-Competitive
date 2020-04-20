
#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define mod 1000000007

void multiply(lli A[2][2], lli M[2][2])
{
	A[0][0] %= (mod - 1);
	A[0][1] %= (mod - 1);
	A[1][0] %= (mod - 1);
	A[1][1] %= (mod - 1);

	M[0][0] %= (mod - 1);
	M[0][1] %= (mod - 1);
	M[1][0] %= (mod - 1);
	M[1][1] %= (mod - 1);

	lli first = ( A[0][0] * M[0][0] ) %(mod - 1)  + ( A[0][1] * M[1][0] ) %(mod - 1); 	
	lli second = ( A[0][0] * M[0][1] ) %(mod - 1) + ( A[0][1] * M[1][1] ) %(mod - 1); 
	lli third = ( A[1][0] * M[0][0] ) %(mod - 1) +  ( A[1][1] * M[1][0] ) %(mod - 1); 
	lli fourth = ( A[1][0] * M[0][1] ) %(mod - 1) + ( A[1][1] * M[1][1] ) %(mod - 1); 

	A[0][0] = first%(mod - 1);
	A[0][1] = second%(mod - 1);
	A[1][0] = third%(mod - 1);
	A[1][1] = fourth%(mod - 1);
}

void power(lli A[2][2] , lli n)
{
	if(n <= 1) return;

	power(A,n/2);
	multiply(A,A);

	if(n%2 == 1) // if n is odd
	{
		lli M[2][2] =  { {1,1},{1,0} };
		multiply(A,M);
	}
}

lli mod_power(lli n, lli m, lli p) //(n^m) mod p
{
	if (m == 1) return n;
	if (m == 0) return 1;
	lli temp = (n*n)%p;
	if (m % 2 != 0)
		return (n * mod_power(temp, m/2, p))%p;
	else return mod_power(temp, m/2, p)%p;
}

lli solver (lli g0, lli g1, lli n)
{
	lli A[2][2] =  { {1,1},{1,0} };
	power(A,n-1);
	// A[0][0] = f(n) and A[1][0] = f(n-1)

	A[0][0] %= (mod - 1);
	A[1][0] %= (mod - 1);
	
	lli a = mod_power(g0, A[1][0], mod);
	lli b = mod_power(g1, A[0][0], mod);
	return (a * b)%mod;
}

int main ()
{
	int t;
	cin >> t;
	lli f0, f1, n;
	while(t--)
	{
		cin >> f0 >> f1 >> n;
		if (n == 0) cout << f0 << endl;
		else if (n == 1) cout << f1 << endl;
		else cout << solver(1+f0, 1+f1, n) - 1 << endl;
	}
	return 0 ; 
}
