#include <iostream>
#include <algorithm>
using namespace std;

void maxProd(int arr[],int n){
    int res=*max_element(arr,arr+n);  //initializing result with max of array
    int curMin=1,curMax=1;

    for(int i=0;i<n;i++){
        if(arr[i]==0){
            curMax=curMin=1;  //resetting if 0 occurs
            continue;
        }
        int tempMx=curMax; //saving curMax in temp as its val will change
        curMax = max(arr[i]*curMax,max(arr[i]*curMin,arr[i]));
        curMin = min(arr[i]*tempMx,min(arr[i]*curMin,arr[i]));
        res = max(res,curMax);
    }
    cout<<"Max prod: "<<res;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    maxProd(arr,n);
  return 0;
}
/*
7
1 -2 -3 0 7 -8 -2
Ans: 112
*/
