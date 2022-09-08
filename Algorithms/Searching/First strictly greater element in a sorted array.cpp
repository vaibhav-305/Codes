/*
Given a sorted array and a target value, find the first element that is strictly greater than given element.

Examples:

Input : arr[] = {1, 2, 3, 5, 8, 12}
        Target = 5
Output : 4 (Index of 8)

Input : {1, 2, 3, 5, 8, 12}
        Target = 8
Output : 5 (Index of 12)

Input : {1, 2, 3, 5, 8, 12}
        Target = 15
Output : -1
*/
#include <iostream>
using namespace std;

int next(int arr[], int target, int n)
{
    int start = 0,endi=n-1;

    int ans = -1;
    if(arr[endi]<=target)
        return -1;
    while (start <= endi)
    {
        int mid = (start + endi) / 2;

        // Move to right side if target is
        // greater.
        if (arr[mid] <= target)
            start = mid + 1;

        // Move left side.
        else
        {
            ans = mid;
            endi = mid - 1;
        }
    }

    return ans;
}

// Driver code
int main()
{
    int arr[] = {10, 15, 20, 20, 25, 30, 35};
    int n = sizeof(arr) / sizeof(arr[0]);
    int indx=next(arr, 30, n);
    if(indx==-1) cout<<"index: -1 not found"<<endl;
    else  cout<<"Answer: arr["<<indx<<"]= "<<arr[indx];
    return 0;
}
