//! T.C.= O(n*n) + O(n*log(n)){of sorting array once}         S.C.= O(1)
//This is optimal approach
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> solve3sum(vector<int> , int );

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];


    vector<vector<int>> ans=solve3sum(arr,target);
    cout<<"-------------------------------------\n";
    for(vector<int> v:ans)
    {
        for(int i:v)
            cout<<i<<" ";
        cout<<"\n";
    }
  return 0;
}
vector<vector<int>> solve3sum(vector<int> arr, int target)
{
    int n=arr.size();
    vector<vector<int>> ans;
    vector<int> triplet(3);

    if(n<3)
        return ans;

    sort(arr.begin(), arr.end());

    int i=0,left,right,prev_i,prev_l,prev_r,tempsum;
    while(i<n-2)
    {
        tempsum=target-arr[i];
        left=i+1,right=n-1;
        while(left<right)      //as we cant take the same element twice so left!=right
        {
            if(arr[left]+arr[right]<tempsum)
                left++;
            else if(arr[left]+arr[right]>tempsum)
                right--;
            else{                 //arr[left]+arr[right]
                triplet[0]=arr[i];
                triplet[1]=arr[left];
                triplet[2]=arr[right];
                ans.push_back(triplet);
                prev_l=arr[left];
                prev_r=arr[right];
                while(left<n)
                {
                    if(prev_l!=arr[left])
                        break;
                    left++;
                }
                while(right>i+1)
                {
                    if(prev_r!=arr[right])
                        break;
                    right--;
                }
            }
        }
        prev_i=arr[i];
        while(i<n-2)
        {
            if(arr[i]!=prev_i)
                break;
            i++;
        }
    }
    return ans;
}
/*
5 0
-1 0 1 2 -1 -4

11 0
-1 -2 -2 -1 -1 2 0 2 0 0 2
*/
