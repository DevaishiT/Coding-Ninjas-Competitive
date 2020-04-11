#include <bits/stdc++.h>

using namespace std;

long long merge(int a[], int left, int mid, int right) 
{ 
    int i, j, k; 
    int n1 = mid - left + 1; 
    int n2 =  right - mid; 
    long long num = 0;

    int L[n1];
    int R[n2];

    for (i = 0; i < n1; i++) 
        L[i] = a[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[mid + 1+ j]; 

    i = 0; 
    j = 0; 
    k = left; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k] = L[i]; 
            i++; 
        } 
        else
        { 
            num = num + (n1 - i);
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
    return num;
}

long long mergesort(int a[], int left, int right) 
{ 
    int mid;
    long long inv_count = 0; 
    if (right > left) { 
    
        mid = left + (right - left) / 2; 
        inv_count += mergesort(a, left, mid); 
        inv_count += mergesort(a, mid + 1, right); 
        inv_count += merge(a, left, mid, right); 
    } 
    return inv_count; 
} 


long long solve(int A[], int n)
{
	return mergesort(A, 0, n-1);
}