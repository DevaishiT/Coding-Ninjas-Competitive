#include<bits/stdc++.h>

using namespace std;

int main ()
{
	int n;
	cin >> n;

	if (n == 0 || n == 1)
	{
		cout<<0<<endl;
		return 0;
	} 

	vector<bool> arr(n+1, true);
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
		if (arr[i] == true) count++;
	cout<<count<<endl;

	return 0;
}
