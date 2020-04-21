
#include<bits/stdc++.h>
using namespace std;

int solver( vector<vector<int>> input, int r, int c)
{
	int res = INT_MIN;
	for(int i=0; i<c; i++)
	{
		vector<long int> sum(r,0);
        for(int j=i; j<c; j++)
		{
			for(int k=0; k<r; k++) sum[k] += input[k][j];

			int max_so_far = INT_MIN;
			int max_till_here = 0;
			for(int i=0; i<r; i++)
			{
				max_till_here += sum[i];
				max_so_far = max(max_so_far, max_till_here);
				if(max_till_here < 0)
					max_till_here = 0;
			}
			res = max(max_so_far, res);
		}
		//for(int k=0; k<r; k++) sum[k] -= input[k][i];
	}
	return res;
}

int main ()
{
	int r, c;
	cin >> r >> c;
	vector<vector<int>> arr(r, vector<int> (c,0));
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			cin >> arr[i][j];
	cout << solver(arr, r, c) << endl;
	return 0;
}
