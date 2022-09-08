/// In this problem all the elements of array are +ve. For -ve values go to: https://www.geeksforgeeks.org/longest-sub-array-sum-k/
//In this problem sum k is given and we have to find the max length subarray with sum k.
//T.C= O(n) - 2 traversals         S.C.= O(1)
#include <iostream>
using namespace std;
typedef long long int llt;

int largest_subarray(int *, int , llt );

int main()
{
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    llt k;
    cout<<"enter the sum whose longest subarray you want to find:";
    cin>>k;

    cout<<largest_subarray(arr,n,k);
    return 0;
}

int largest_subarray(int arr[], int n, llt k)
{
    int i=0,j=0,mx=INT_MIN,starting_index;
    llt sum=0;
    while(j<n)
    {
        sum+=(llt)arr[j];

        if(sum<k)
        {
            j++;
        }

        else if(sum==k)
        {
            //mx=max(mx,j-i+1);       //we'd modify just max to min if we need to find smallest subarray with sum k
            if(mx<j-i+1)
            {
                mx=j-i+1;
                starting_index=i;
            }
            j++;
        }

        else    /// (sum > k) condition
        {
            while(sum>k)
            {
                sum-=(llt)arr[i];
                i++;
            }
            j++;
        }
    }
    cout<<"Starting index: "<<starting_index<<endl;

    return mx;
}
/*
7
4 1 1 1 2 3 5
5
Ans: 4

6
10 5 2 7 1 9
15
Ans: 4
*/
