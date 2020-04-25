#include<bits/stdc++.h>

using namespace std;

struct trie
{
	int pri;
	trie *children[26];
	trie()
	{
		pri = 0;
		for(int i=0; i<26; i++) 
			children[i] = NULL;
	}
};

trie *root;

void insert_trie(string input, int priority)
{
	trie *node = root;
	
	for(int i=0; i<input.length(); i++)
	{
		char c = input[i];
		if (node->children[c - 'a'] == NULL)
		{
			trie *temp = new trie;
			temp->pri = priority;
			node->children[c -'a'] = temp;
		}
		else
		{
			node->children[c -'a']->pri = 
				max(node->children[c -'a']->pri, priority);
		}
		node = node->children[c - 'a'];
	}
}

int query(string input)
{	
	trie *node = root;
	
	for(int i=0; i<input.length(); i++)
	{
		char c = input[i];
		if (node->children[c - 'a'] == NULL)
			return -1;
		else node = node->children[c - 'a'];
	}

	return node->pri;
}

int main()
{
	int n, q;
	cin >> n >> q;

	string input;
	int priority;
	root = new trie;
	for(int i=0; i<n; i++)
	{
		cin >> input;
		cin >> priority;
		insert_trie(input, priority);
	}
	for(int i=0; i<q; i++)
	{
		cin >> input;
		cout << query(input) << endl;
	}
	return 0;
}