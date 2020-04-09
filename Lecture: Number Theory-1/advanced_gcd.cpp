#include<bits/stdc++.h>

using namespace std;

int gcd(int x, int y)
{
	if (y == 0) return x;
	return gcd(y, x%y);
}

int gcd_large(int x, string y)
{
	int num = 0;
	for(int i=0; i<y.length(); i++)
		num = (num*10 + y[i] - 48)%x;
	return gcd(x, num);
}

int main ()
{
	int t;
	cin >> t;

	int x;
	string y;
	for(int i=0; i<t; i++)
	{
		cin >> x >> y;
		if (x == 0)
		{
			cout<<y<<endl;
			continue;
		}
		cout<<gcd_large(x,y)<<endl;
	}

	return 0;
}
