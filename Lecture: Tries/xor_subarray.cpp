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

int xor_subarray(vector<int> &arr, int n, trienode *head)
{
	int xor_sum = arr[0];
	insert(head, xor_sum);
	int max_sum = arr[0];
	for(int i=1; i<n; i++)
	{
		xor_sum = xor_sum^arr[i];
		max_sum = max(max_sum, pair_xor(arr, xor_sum, n, head));
		insert(head, xor_sum);
	}
	return max_sum;
}

int main ()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	trienode *root = new trienode;

	for(int i=0; i<n; i++) cin >> arr[i];
	cout << xor_subarray(arr, n, root) << endl;
}