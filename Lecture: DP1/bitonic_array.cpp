
#include <bits/stdc++.h>

using namespace std;

vector<int> increasing_subsequence( int *arr, int len)
{
	vector<int> output(len,1);
	
	for(int i= 1; i<len; i++)
	{
		for(int j = i-1; j>=0; j--)
		{
			if (arr[j] >= arr[i]) continue;
			if(output[i] < (output[j]+1)) output[i] = output[j]+1;
		}
	}
	return output;
}

vector<int> decreasing_subsequence( int *arr, int len)
{
	vector<int> output(len,1);
	
	for(int i= len-2; i>=0; i--)
	{
		for(int j = i+1; j <= len-1; j++)
		{
			if (arr[j] >= arr[i]) continue;
			if(output[i] < (output[j]+1)) output[i] = output[j]+1;
		}
	}
	return output;
}

int longestBitonicSubarray(int *input, int n) 
{
    vector<int> a = increasing_subsequence(input,n);
	vector<int> b = decreasing_subsequence(input,n);
	int res =0;
	for(int i=0; i<n; i++)
		res = max(res, (a[i] + b[i] - 1));
	return res;
}