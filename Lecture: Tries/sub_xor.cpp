#include<bits/stdc++.h>
#define BIT_SIZE 21
#define MAX_SIZE 100002

using namespace std;

struct trie
{
	int cnt;
	trie *children[2];
	trie()
	{
		cnt = 0;
		children[0] = children[1] = NULL;
	}
};

trie *root;
int A[MAX_SIZE];

void insert_trie(int val)
{
	trie *node = root, *newNode, temp;
	int i=0;
	for(i=BIT_SIZE-1;i>=0;i--)
	{
		bool k=(1<<i)&val;
		if (node->children[k]==NULL)
		{
			newNode = new trie;
			newNode->cnt = 1;
			node->children[k] = newNode;
		}
		else (node->children[k]->cnt)++;
		node = node->children[k];
	}
}

long long int query(int val, int k)
{
	int i=BIT_SIZE-1;
	long long ans = 0;
	trie *node = root;
	if (root == NULL)
		return 0;
	while(i>=0)
	{
		bool p=(1<<i)&val;
		bool q=(1<<i)&k;

		if (q==1)
		{
			if (node->children[p]!=NULL)
			{
				ans+=node->children[p]->cnt;
			}
			node = node->children[1-p];
		}
		else
		{
			node = node->children[p];
		}
		if (node == NULL) break;
		i--;
	}
	return ans;
}

int main()
{
	int t, n, i, mxor, k;
	long long ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		root = new trie;
		mxor=0;
		ans=0;
		insert_trie(mxor);
		for(int i=0; i<n; i++)
		{
			cin>>A[i];
			mxor^=A[i];
			ans += query(mxor, k);
			insert_trie(mxor);
		}
		cout<<ans<<endl;
	}
}