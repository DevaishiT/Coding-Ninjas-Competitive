#include <vector>
#include <algorithm>

using namespace std;

int kthLargest (vector<int> arr, int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    sort(arr.begin(), arr.end(), greater<int>());
    return arr[k - 1];
}

