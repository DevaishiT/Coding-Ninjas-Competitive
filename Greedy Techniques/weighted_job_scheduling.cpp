#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

struct job {
	int start;
	int end;
	int weight;
};

bool compare (job a, job b)
{
	return (a.end < b.end);
}

int in_interval(job *arr, int key, int l, int r)
{
	if (l > r) return -1;
	if (l == r)
	{
		if (arr[l].end <= key) return l;
		else return -1;
	}
	int mid = l + (r - l)/2;
	if (arr[mid].end == key) return mid;
	else if (arr[mid].end < key)
	{
		int temp = in_interval(arr, key, mid+1, r);
		if (temp == -1) return mid;
		else return temp;
	}
	else return in_interval(arr, key, l, mid-1);
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n;
	cin >> n;

	job *arr = new job[n];
	for(int i=0; i<n; i++)
		cin >> arr[i].start >> arr[i].end >> arr[i].weight;

	sort(arr, arr+n, compare);

	int *dp = new int[n];
	dp[0] = arr[0].weight;


	for(int i=1; i<n; i++)
	{
		int val = arr[i].weight;
		int ind = in_interval(arr,arr[i].start,0,i-1);
		if (ind != -1) val += dp[ind];
		dp[i] = max(dp[i-1], val);
	}

	cout << dp[n-1] << "\n";
	return 0 ; 
}