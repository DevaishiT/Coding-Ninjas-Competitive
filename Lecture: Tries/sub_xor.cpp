#include<bits/stdc++.h>
using namespace std;

class trienode {

public:
	trienode *left;
	trienode *right;

	trienode()
	{
		this->left = this->right = NULL;
	}
};

void insert(trienode *head, int val)
{
	trienode *curr = head;
	for(int i=31; i>=0; i--)
	{
		int b = (val>>i)&1;

		if (b == 0)
		{
			if (curr->left == NULL)
				curr->left = new trienode();
			curr = curr->left;
		}
		else
		{
			if (curr->right == NULL)
				curr->right = new trienode();
			curr = curr->right;
		}
	}
	return;
}
/*
int pair_xor(vector<int> &arr, int val, int n, trienode *head)
{
		int curr_max = 0;
		trienode *curr = head;
		for(int j=31; j>=0; j--)
		{
			int b = (val>>j)&1;

			if (b == 0)
			{
				if (curr->right != NULL)
				{
					curr_max += (1 << j); // same as 2^j
					curr = curr->right;
				}
				else curr = curr->left;
			}
			else
			{
				if (curr->left != NULL)
				{
					curr_max += (1 << j); // same as 2^j
					curr = curr->left;
				}
				else curr = curr->right;
			}
		}
	return curr_max;
}
*/

int sub_xor(int val, int k, trienode *head, int temp)
{
	if (head->left == NULL && head->right == NULL)
	{
		//Terminating Condition
		int temp2 = temp^val;
		//cout << temp2 << " ";
		if (temp2 < k)
		{
			return 1;
		}
		else return 0;
	}

	int temp2 = temp;
	int count = 0;
	if (head->left != NULL)
	{
		temp2 = (temp2<<1);
		count += sub_xor(val,k,head->left,temp2);
		temp2 = temp;
	}

	if (head->right != NULL)
	{
		temp2 = (temp2<<1) + 1;
		count += sub_xor(val,k,head->right,temp2);
		temp2 = temp;
	}
	return count;
}

int count_xor_subarray(vector<int> &v, int n, int k)
{
	trienode *head = new trienode();
	int xor_sum = v[0];
	insert(head, xor_sum);
	int count = (v[0] < k)? 1 : 0;
	for(int i=1; i<n; i++)
	{
		xor_sum = xor_sum^v[i];
		if (xor_sum < k) count++;
		count += sub_xor(xor_sum, k, head, 0);
		//cout << endl;
		insert(head, xor_sum);
	}
	return count;
}

int main ()
{
	int t;
	cin >> t;
	int n, k;
	vector<int> v;
	while(t--)
	{
		cin >> n >> k;
		v.resize(n);
		for(int i=0; i<n; i++) cin >> v[i];
		cout << count_xor_subarray(v, n, k) << endl;
	}
	return 0;
}