//! T.C.= O(n)       S.C.= O(1)
//This is the most optimal approach
#include <iostream>
using namespace std;

int amount_trapped(int *,int);

int main()
{
    int n;
    cin>>n;
    int heights[n];
    for(int i=0;i<n;i++)
        cin>>heights[i];

    cout<<amount_trapped(heights,n);
  return 0;
}
int amount_trapped(int heights[],int n)
{
    if(n<3)
        return 0;

    int amt=0,left=0,right=n-1,maxL=-1,maxR=-1;
    while(left<=right)
    {
        if(heights[left]<=heights[right])
        {
            maxL=max(maxL,heights[left]);
            amt+=maxL-heights[left];
            left++;
        }
        else
        {
            maxR=max(maxR,heights[right]);
            amt+=maxR-heights[right];
            right--;
        }
    }
    return amt;
}
/*
12
0 1 0 2 1 0 1 3 2 1 2 1
*/
