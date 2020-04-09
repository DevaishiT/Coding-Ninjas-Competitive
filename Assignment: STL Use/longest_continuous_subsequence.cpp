#include <bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	//Your Code goes here
    vector<int> v;
    if (n == 0) return v;
    unordered_set <int> s;
    int start = arr[0];
    int num = 1;
    for (int i=0; i<n; i++) s.insert(arr[i]);
    for (int i=0; i<n; i++)
    {
        if (s.find(arr[i] - 1) == s.end())
        {
            int temp = arr[i];
            while (s.find(temp++) != s.end());
            if (temp - arr[i] > num)
            {
                start = arr[i];
                num = temp - arr[i];
            }
        }
    }
    for (int i=0; i<num-1; i++) v.push_back(start++);
    return v;
}
