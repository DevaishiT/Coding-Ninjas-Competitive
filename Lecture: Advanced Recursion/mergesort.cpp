void merge(int a[], int left, int mid, int right) 
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
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
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
    return;
}

void mergesort(int a[], int left, int right) {
    int mid;
    if (right > left) { 
    
        mid = left + (right - left) / 2; 
        mergesort(a, left, mid); 
        mergesort(a, mid + 1, right); 
        merge(a, left, mid, right); 
    } 
    return; 
}

void mergeSort(int input[], int size){
	
    mergesort(input,0,size - 1);
    return;        
}
