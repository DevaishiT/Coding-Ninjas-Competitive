#include <bits/stdc++.h>

using namespace std;

void keypadprint(int input, string output)
{
	map <int,string> m;

	m[2] = "abc";
	m[3] = "def";
	m[4] = "ghi";
	m[5] = "jkl";
	m[6] = "mno";
	m[7] = "pqrs";
	m[8] = "tuv";
	m[9] = "wxyz";	

	if(input == 0)
	{
		cout << output << endl;
		return;
	}

	int digit = input % 10;
	int options = m[digit].length();

	for(int i=0; i<options; i++)
		keypadprint(input/10, m[digit][i] + output);

	//int size = keypad(input/10, output);
	return;
}

void printKeypad(int num){
  
  string output = "";
  keypadprint(num,output);
}
