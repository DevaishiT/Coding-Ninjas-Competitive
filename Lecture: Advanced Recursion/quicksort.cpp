int partition(int a[], int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }
  int temp = a[l];
  a[l] = a[j];
  a[j] = temp;
  return j;
}

void quick_sort(int a[], int l, int r) {
  if (l >= r) {
    return;
  }
  int k = l + rand() % (r - l + 1);
  int temp = a[l];
  a[l] = a[k];
  a[k] = temp;
  int m = partition(a, l, r);

  quick_sort(a, l, m - 1);
  quick_sort(a, m + 1, r);
}

void quickSort(int input[], int size) {
	quick_sort(input,0,size -1); 
	return;
}
