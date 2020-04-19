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
	for(int i=2; i<=n; i++)
		if (arr[i] == true && (n % i == 0)) primes.push_back(i);
	
	return primes;
}

bool divisible( vector<pair<int,int>> &a, vector<pair<int,int>> &b)
{
	for(int i=0; i<a.size(); i++)
	{
		if (a[i].second > b[i].second) return false;
	}
	return true;
}

int main(){
	// Write your code here
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i=0; i<n; i++) cin >> arr[i];

    vector<pair<int,int>> vp;

	vector<int> v = primes_n(k);
	int temp = k;
	int count;
	for(int i=0; i<v.size(); i++)
	{
		count = 0;
		while (k % v[i] == 0)
		{
			k /= v[i];
			count++;
		}
		vp.push_back(make_pair(v[i], count));
	}
	k = temp;
	// for(int i=0; i<vp.size(); i++)
	// 	cout<<vp[i].first<<" "<<vp[i].second<<endl;

	vector<pair<int,int>> vq = vp;
	for(int i=0; i<vq.size(); i++) vq[i].second = 0;
	
	int i = 0, j = -1;
	count = 0;
	for(; i < n; i++)
	{
		if (divisible(vp, vq)) count += n-j;
		else
		{
			j++;
			for(; j < n; j++)
			{
				//arr[i] to arr[j] (both included)
				temp = arr[j];
				for(int a = 0; a < vq.size(); a++)
				{
					while (temp % vq[a].first == 0)
					{
						vq[a].second++;
						temp /= vq[a].first;
					}
				}
				if (divisible(vp, vq))
				{
					//cout<<j<<endl;
					count += n-j;
					break;
				}
			}
		}
		
		temp = arr[i];
		for(int a = 0; a < vq.size(); a++)
		{
			while (temp % vq[a].first == 0)
			{
				vq[a].second--;
				temp /= vq[a].first;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}