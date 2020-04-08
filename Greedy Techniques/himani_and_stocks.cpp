#include<bits/stdc++.h>
using namespace std;

typedef long long lli;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	
	lli n,M;
	lli a,b;

	cin >> n >> M;
	cin >> a >>b;

	lli num = pow(2,32);

	lli *x = new lli[n+1];
	lli *c = new lli[n+1];

	x[0] = 0;

	for(int i=1;i<=n;i++)
	{
		x[i] = ( ( (x[i-1]%M)*a ) + b ) % num;
		c[i] = x[i]/256;
	}

	lli profit = 0;
	lli current = c[1];

	for(int i=2;i<n;i++)
	{
		if( c[i] > c[i+1])
		{
			profit += c[i] - current;
			cur = c[i+1];
			continue;
		}
		if(i == n-1) profit += c[n] - current;
	}
	cout << profit << "\n";
	return 0 ; 
}