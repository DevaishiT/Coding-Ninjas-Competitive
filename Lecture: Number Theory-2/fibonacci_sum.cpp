#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

void multiply(unsigned long long A[2][2], unsigned long long M[2][2])
{
	A[0][0] %= mod;
	A[0][1] %= mod;
	A[1][0] %= mod;
	A[1][1] %= mod;

	M[0][0] %= mod;
	M[0][1] %= mod;
	M[1][0] %= mod;
	M[1][1] %= mod;

	unsigned long long first = ( A[0][0] * M[0][0] ) %mod  + ( A[0][1] * M[1][0] ) %mod; 	
	unsigned long long second = ( A[0][0] * M[0][1] ) %mod + ( A[0][1] * M[1][1] ) %mod; 
	unsigned long long third = ( A[1][0] * M[0][0] ) %mod +  ( A[1][1] * M[1][0] ) %mod; 
	unsigned long long fourth = ( A[1][0] * M[0][1] ) %mod + ( A[1][1] * M[1][1] ) %mod; 

	A[0][0] = first%mod;
	A[0][1] = second%mod;
	A[1][0] = third%mod;
	A[1][1] = fourth%mod;
}

void power(unsigned long long A[2][2] , int n)
{
	if(n <= 1) return;

	power(A,n/2);
	multiply(A,A);

	if(n%2 == 1) // if n is odd
	{
		unsigned long long M[2][2] =  { {1,1},{1,0} };
		multiply(A,M);
	}
}

unsigned long long fib(int n)
{
	unsigned long long A[2][2] =  { {1,1},{1,0} };

	if(n == 0)
		return 0;

	power(A,n-1);
	return A[0][0]%mod;
}

unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{
	// Write your code here
    unsigned long long temp = (fib(n+2)%mod - fib(m+1)%mod + mod)%mod;
    return temp;
}


