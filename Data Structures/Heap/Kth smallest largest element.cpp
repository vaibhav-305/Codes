//! T.C. =  O(n*log(k))       S.C. = O(k)
#include <iostream>
#include <queue>
using namespace std;

int Kth_smallest(int arr[],int n,int k)
{
    int i=0;
    priority_queue<int> maxH;    //all the elements less than top() are below in max Heap

    while(i<k){       //making a heap of size k
        maxH.push(arr[i]);
        i++;
    }

    while(i<n)      //traversing rest of the array
    {
        if(arr[i] < maxH.top()){
            maxH.pop();
            maxH.push(arr[i]);
        }
        i++;
    }
    return maxH.top();
}
int Kth_largest(int arr[],int n,int k)
{
    int i=0;
    priority_queue<int,vector<int>,greater<int>> minH;   //all the elements greater than top() are below in min Heap

    while(i<k){   //making a heap of size k
        minH.push(arr[i]);
        i++;
    }

    while(i<n)   //traversing rest of array
    {
        if(arr[i] > minH.top()){
            minH.pop();
            minH.push(arr[i]);
        }
        i++;
    }
    return minH.top();
}
int main()
{
    int n,k;
    cin>>n>>k;     // n >= k
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<Kth_smallest(arr,n,k);
    cout<<"\n";
    cout<<Kth_largest(arr,n,k);
  return 0;
}
/*
9 8
1 5 9 10 11 12 13 13 15
Ans: Kth smallest: 13
     Kth largest: 5
4 2
1 2 1 3
Ans: Kth smallest: 1
     Kth largest: 2
25 5
1 4 7 11 15 2 5 8 12 19 3 6 9 16 22 10 13 14 17 24 18 21 23 26 30
Ans: 5 22
*/
