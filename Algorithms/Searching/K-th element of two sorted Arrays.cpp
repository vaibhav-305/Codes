/* Problem:
Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the k’th position of the final sorted array.
*/
//! T.C.= O(log(min(n1,n2)))           S.C.= O(1)
#include <iostream>
using namespace std;

int Kth_element(int *,int ,int *, int, int);

int main()
{
    int n1,n2,k;
    cin>>n1>>n2>>k;
    int arr1[n1],arr2[n2];
    for(int i=0;i<n1;i++)
        cin>>arr1[i];
    for(int i=0;i<n2;i++)
        cin>>arr2[i];
    cout<<Kth_element(arr1,n1,arr2,n2,k);
  return 0;
}

int Kth_element(int arr1[],int n1,int arr2[],int n2,int k)
{
    //if length of arr1 > length of arr2, switch the arrays so that n1 is always smaller for our further code
    if(n1>n2)
        return Kth_element(arr2,n2,arr1,n1,k);

    //First, if k exceeds the length of the first array, we need to take the last element as the right border. The reason for this is quite straightforward, as we cannot take more elements from the array than there are.
    //Second, if k is bigger than the number of elements in the second array, we know for sure that we need to take at least (k - length(list2)) from the first array. As an example, let's say k = 7. As the second array only has four elements, we know that we need to take at least 3 elements from the first array, so we can set L to 2:
    //Take eg: [7,12,14,15]
    //         [1,2,3,4,9,11]    k=3  ,  k=7
    int low=max(0,k-n2);         // correct left boundary if k is bigger than the size of list2
                                 // int left = k < list2.length ? 0 : k - list2.length;

    int high=min(k,n1);         // the inital right boundary cannot exceed the list1
                                // int right = min(k-1, list1.length);

    int partition1,partition2,maxLeft1,maxLeft2,minRight1,minRight2;
    while(low<=high)
    {
        partition1=(low+high)/2;
        partition2=k-partition1;

        //if mid1 is 0, it means nothing is there on left side. Use -INF for maxLeft1
        //if mid1 is n1, it means nothing is there on right side. Use +INF for minRight1
        maxLeft1= (partition1==0)?INT_MIN:arr1[partition1-1];
        minRight1= (partition1==n1)?INT_MAX:arr1[partition1];

        maxLeft2= (partition2==0)?INT_MIN:arr2[partition2-1];
        minRight2= (partition2==n2)?INT_MAX:arr2[partition2];


        if(maxLeft1<=minRight2 && maxLeft2<=minRight1)
        {
            /// We have found the correct partition
            return max(maxLeft1,maxLeft2);
        }
        else if(maxLeft1>minRight2)  //we are too far on right side for mid1, go left
            high=partition1-1;
        else
            low=partition1+1;
    }
    return -1;  //Input arrays are not sorted
}
/*
5 4 5
2 3 6 7 9
1 4 8 10

5 7 7
100 112 256 349 770
72 86 113 119 265 445 892
*/
