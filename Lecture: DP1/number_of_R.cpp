#include<bits/stdc++.h>

using namespace std;

bool all_negative(int *arr, int n)
{	
	for(int i=0;i<n;i++)
		if(arr[i] > 0) return false;
	return true;	
}

int solver(string input)
{
	int len = input.length();
	int count = 0;
	int arr[len];
	for(int i=0; i<len; i++)
	{
		if (input[i] == 'R') 
		{
			arr[i] = -1;
			count++;
		}
		else arr[i] = 1;
	}

	if (all_negative(arr, len)) return (len - 1);

	//for(int i=0; i<len;i++) cout << arr[i] << endl;
	//cout << endl;

	int max_so_far = INT_MIN;
	int max_till_here = 0;
	for(int i=0; i<len; i++)
	{
		max_till_here += arr[i];
		if(max_so_far < max_till_here)
			max_so_far = max_till_here;
		if(max_till_here < 0)
			max_till_here = 0;
	}
	//cout << endl;
	return (max_so_far + count);
}

int main ()
{
	int t;
	cin >> t;
	string input;
	while(t--)
	{
		cin >> input;
		cout << solver(input) << endl;	
	}
	return 0;
}