//! Link: https://www.geeksforgeeks.org/sum-xor-possible-subsets/
#include <iostream>
#include <math.h>
using namespace std;

// Returns sum of XORs of all subsets
int xorSum(int arr[], int n)
{
    int bits = 0;

    // Finding bitwise OR of all elements
    for (int i=0; i < n; ++i)
        bits |= arr[i];

    int ans = bits * pow(2, n-1);

    return ans;
}

// Driver code
int main()
{
    int arr[] = {1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << xorSum(arr, size);
}
