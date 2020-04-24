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

int pair_xor(vector<int> &arr, int n, trienode *head)
{
	int maximum = INT_MIN;
	for(int i=0; i<n; i++)
	{
		int val = arr[i];
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
		maximum = max(maximum, curr_max);
	}
	return maximum;
}

int main ()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	trienode *root = new trienode;

	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
		insert(root,arr[i]);
	} 
	cout << pair_xor(arr, n, root) << endl;
}