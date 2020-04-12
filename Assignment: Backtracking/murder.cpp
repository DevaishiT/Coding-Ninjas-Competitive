#include <bits/stdc++.h>

using namespace std;

long long merge(int a[], int left, int mid, int right) 
{ 
    int i, j, k; 
    int n1 = mid - left + 1; 
    int n2 =  right - mid; 

    int L[n1];
    int R[n2];

    for (i = 0; i < n1; i++) 
        L[i] = a[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[mid + 1+ j]; 

    i = 0; 
    j = 0; 
    k = left;

    long long sum = 0; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] < R[j]) 
        { 
            sum += L[i]*(n2 - j);
            a[k] = L[i]; 
            i++; 
        } 
        else
        { 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        a[k] = R[j]; 
        j++; 
        k++; 
    } 
    return sum;
}

long long mergesort(int a[], int left, int right) 
{ 
    int mid;
    long long sum = 0; 
    if (right > left) { 
    
        mid = left + (right - left) / 2; 
        sum += mergesort(a, left, mid); 
        sum += mergesort(a, mid + 1, right); 
        sum += merge(a, left, mid, right); 
    } 

    return sum; 
} 

int main() 
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        int n;
        cin >> n;
        int a[n];
        for (int j = 0; j < n; j++) cin >> a[j];
        cout<<mergesort(a, 0, n-1)<<endl;
    }
}