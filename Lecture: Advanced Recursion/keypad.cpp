#include <bits/stdc++.h>

using namespace std;

int keypad(int input, string output[])
{	
	if (input == 0)
	{
		output[0] = "";
		return 1;
	} 
	map <int,string> m;

	m[2] = "abc";
	m[3] = "def";
	m[4] = "ghi";
	m[5] = "jkl";
	m[6] = "mno";
	m[7] = "pqrs";
	m[8] = "tuv";
	m[9] = "wxyz";

	int digit = input % 10;
	int size = keypad(input/10, output);
	int options = m[digit].length();

	string dupl[1000];
	for(int i=0; i<size; i++) dupl[i] = output[i];

	for(int i=0; i<options; i++)
		for(int j=0; j<size; j++)
			output[i*size + j] = dupl[j] + m[digit][i];

	return (options*size);
}