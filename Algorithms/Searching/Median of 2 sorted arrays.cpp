//!Time complexity of this method: O(log(min(n1,n2)))        S.C.= O(1)
#include <iostream>
using namespace std;

double median(int *,int ,int *,int );

int main()
{
    int n1,n2;
    cin>>n1>>n2;
    int arr1[n1],arr2[n2];
    for(int i=0;i<n1;i++)
        cin>>arr1[i];
    for(int i=0;i<n2;i++)
        cin>>arr2[i];
    cout<<median(arr1,n1,arr2,n2);
  return 0;
}

double median(int arr1[],int n1,int arr2[],int n2)
{
    //if length of arr1 > length of arr2, switch the arrays so that n1 is always smaller for our further code
    if(n1>n2)
        return median(arr2,n2,arr1,n1);

    int low=0;
    int high=n1;
    int partition1,partition2,maxLeft1,maxLeft2,minRight1,minRight2;
    while(low<=high)
    {
        partition1=(low+high)/2;
        partition2=(n1+n2+1)/2-partition1;

        //if mid1 is 0, it means nothing is there on left side. Use -INF for maxLeft1
        //if mid1 is n1, it means nothing is there on right side. Use +INF for minRight1
        maxLeft1= (partition1==0)?INT_MIN:arr1[partition1-1];
        minRight1= (partition1==n1)?INT_MAX:arr1[partition1];

        maxLeft2= (partition2==0)?INT_MIN:arr2[partition2-1];
        minRight2= (partition2==n2)?INT_MAX:arr2[partition2];

        if(maxLeft1<=minRight2 && maxLeft2<=minRight1)
        {
            /// We have found the correct partition
            /*
            If the combined length (n1+n2) is odd:
                    median is the max of left part of both arrays
            If n1+n2 is even:
                    median will be the average of max of left and min of right of both arrays
            */
            if((n1+n2)%2==0){
                double ans= ((double)(max(maxLeft1,maxLeft2)+min(minRight1,minRight2)))/2.0;
                return (double)ans;
            }
            else{
                double ans=(double)(max(maxLeft1,maxLeft2));
                return (double)ans;
            }
        }
        else if(maxLeft1>minRight2)  //we are too far on right side for mid1, go left
            high=partition1-1;
        else
            low=partition1+1;
    }
    return (double)(-1);  //Input arrays are not sorted
}
/*
4 6
2 3 5 8
10 12 14 16 18 20

5 6
-5 3 6 12 15
-12 -10 -6 -3 4 10
*/
