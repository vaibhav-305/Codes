/** Dutch National Flag Algorithm OR 3-way Partitioning */
//It is a modificaton of Quick sort Algo
//Used when array is having only 3 values multiple times eg. (an array of 0's, 1's and 2's only)
//eg: arr=[0,2,2,0,2,1]
//O(N) time and O(1) space,only one time array is transversed.
/**
Algo:
    l=0;
    mid=0;
    r=n-1;
    Check value of arr[mid]-
        if 0, swap arr[low] and arr[mid], low++, mid++
        if 1, mid++
        if 2, swap arr[mid] and arr[high], high--
*/

#include <iostream>
using namespace std;
void Swap(int *a,int *b)
{
    int k=*a;
    *a=*b;
    *b=k;
}

int main() {
	//code
	int n,l,r,mid,swap_cnt=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
        cin>>arr[i];
    //Algo starts from here
    l=0;
    mid=0;
    r=n-1;
    while(mid<=r) //'=' because if array has only 2 types of integer eg. 0's and 1's
    {
        if(arr[mid]==0)
        {
            Swap(&arr[mid],&arr[l]);
            swap_cnt++;
            l++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else if(arr[mid]==2)
        {
            Swap(&arr[mid],&arr[r]);
            swap_cnt++;
            r--;
        }
    }
    //Algo ends here.
    cout<<swap_cnt<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
  return 0;
}

