//! T.C.= O(cols * cols * rows) = O(m*m*n)         S.C.= O(rows) = O(n)
#include <iostream>
#include <vector>
using namespace std;
using llt = long long int;

llt maxSumRectangle(vector<vector<int>> arr);

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];

    cout<<maxSumRectangle(arr);
  return 0;
}
llt kadane(llt arr[],int n,int *starti,int *endi)
{
    llt max_so_far=arr[0], sum=0;
    int s=0;
    *starti=*endi=0;

    for(int i=0;i<n;i++)
    {
        sum+=arr[i];

        if(max_so_far < sum){
            max_so_far=sum;
            *starti=s;
            *endi=i;
        }

        if(sum<0){
            sum=0;
            s=i+1;
        }
    }
    return max_so_far;
}
llt maxSumRectangle(vector<vector<int>> arr)
{
    int n=arr.size(), m=arr[0].size();    // n->rows  m->cols
    int topr,topc,bottr,bottc,starti,endi;      //top row indx , top col indx, bottom row indx, bottom col indx, starti endi are for kadane algo
    llt maxsum=(llt)arr[0][0],sum=0;

    llt curr_row_sums[n];  //array to store all current running individual row sums
    for(int lb=0;lb<m;lb++)      // lb -> column left bound
    {
        fill(curr_row_sums,curr_row_sums+n,0);
        for(int rb=lb;rb<m;rb++)  // rb -> column right bound
        {
            for(int i=0;i<n;i++)
                curr_row_sums[i]+=(llt)arr[i][rb];

            sum=kadane(curr_row_sums,n,&starti,&endi);

            if(sum>maxsum)
            {
                maxsum=sum;
                topr=starti;
                topc=lb;
                bottr=endi;
                bottc=rb;
            }
        }
    }
    cout<<"\nIndex Range: ["<<topr<<", "<<topc<<"] --> ["<<bottr<<", "<<bottc<<"]\n";
    return maxsum;
}
/*
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Ans: 29   (1,1) --> (3,3)
*/
