//! T.C.= O(n*n*n) + O(n*log(n)){of sorting array once}         S.C.= O(1)
//This is optimal approach
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> solve4sum(vector<int>, int );

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];


    vector<vector<int>> ans=solve4sum(arr,target);
    cout<<"-------------------------------------\n";
    for(vector<int> v:ans)
    {
        for(int i:v)
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}
vector<vector<int>> solve4sum(vector<int> arr, int target)
{
    int n=arr.size();
    vector<vector<int>> ans;
    vector<int> quad(4);

    if(n<4)
        return ans;

    sort(arr.begin(), arr.end());

    int i=0,j,left,right,prev_i,prev_j,prev_l,prev_r,tempsum;
    while(i<n-3)
    {
        j=i+1;
        while(j<n-2)
        {
            tempsum=target-arr[i]-arr[j];
            left=j+1,right=n-1;
            while(left<right)     //as we cant take the same element twice so left!=right
            {
                if(arr[left]+arr[right]<tempsum)
                    left++;
                else if(arr[left]+arr[right]>tempsum)
                    right--;
                else                  //arr[left]+arr[right]
                {
                    quad[0]=arr[i];
                    quad[1]=arr[j];
                    quad[2]=arr[left];
                    quad[3]=arr[right];
                    ans.push_back(quad);

                    prev_l=arr[left];
                    prev_r=arr[right];
                    while(left<n)
                    {
                        if(prev_l!=arr[left])
                            break;
                        left++;
                    }
                    while(right>j+1)
                    {
                        if(prev_r!=arr[right])
                            break;
                        right--;
                    }
                }
            }
            prev_j=arr[j];
            while(j<n-2)
            {
                if(arr[j]!=prev_j)
                    break;
                j++;
            }
        }
        prev_i=arr[i];
        while(i<n-3)
        {
            if(prev_i!=arr[i])
                break;
            i++;
        }
    }
    return ans;
}
