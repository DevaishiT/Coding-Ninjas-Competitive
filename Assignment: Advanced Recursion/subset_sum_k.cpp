#include<bits/stdc++.h>
using namespace std;

int subset_sum(int input[], int n, int output[10000][50], int sum[]) 
{
  if(n == 0)
  {
    output[0][0] = 0;
    sum[0] = 0;
    return 1;
  }

  int digit = input[0];
  int size = subset_sum(input + 1, n-1, output, sum);
  //cout<<size<<endl;
  for(int j=0; j<size; j++)
  {
    
    output[size + j][0] = output[j][0] + 1;
    output[size + j][1] = input[0]; 
    sum[size + j] = sum[j] + input[0];
    for(int k=1; k<=output[j][0]; k++)
    {
      output[size + j][k+1] = output[j][k];
    }
  }

  return (2*size);
}

int subsetSumToK(int input[], int n, int output[10000][50], int k)
{
	int mid[10000][50] = {{}};
	int sum[10000] = {0};
	int size = subset_sum(input , n, mid, sum);
	int j = 0;
	for(int i=0; i<size; i++)
	{
		if (sum[i] == k)
		{
			for(int k=0; k<=mid[i][0]; k++)
				output[j][k] = mid[i][k];
			j++;
		}

	}
	return j;
	return 0;
}
