#include<bits/stdc++.h>

using namespace std;

struct triple
{
	int gcd;
	int x; 
	int y;
};

triple extended_gcd(int a, int b)
{
	if (a < b) swap(a,b);
    triple res;

	if (b == 0)
	{
		res.gcd = a;
		res.x = 1;
		res.y = 0;
		return res;
	} 

	triple old = extended_gcd(b,a%b);

	res.gcd = old.gcd;
	res.x = old.y;
	res.y = old.x - (a/b)*old.y;

	return res;
}

int mult_modulo_inverse(int a, int m)
{
	int old = extended_gcd(a, m).x;
	return (old%m + m)%m;
}

long long int count_ways(int a, int b, int d)
{
	int y1 = ((d%a) * mult_modulo_inverse(b,a))%a;

	if (d < y1*b) return 0;
	long long int n = ((d/b) - y1)/a;
	return n+1 ;
}

int main ()
{
	int t;
	cin >> t;
	
	int x, y, d;
	for(int i=0; i<t; i++)
	{
		cin >> x >> y >> d;
        if(d == 0)
		{
			cout << 1 << endl;
			continue;
		}
      
        int res = extended_gcd(x,y).gcd;
         if (d%res != 0)
         {
             cout << 0 << endl;
			 continue;
         }
        x /= res;
        y /= res;
        d /= res;
		cout<<count_ways(x, y, d)<<endl;
	}

	return 0;
}
