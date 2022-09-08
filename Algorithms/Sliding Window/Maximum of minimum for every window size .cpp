// Explanation video link: https://www.youtube.com/watch?v=CK8PIAF-m2E  (Maximum of minimum for every window size ; "GeeksforGeeks Practice" youtube channel)
//! T.C.= O(n)            S.C.= O(n)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> maxOfMin(int *, int );

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<int> ans = maxOfMin(arr,n);
    for(int i:ans)
        cout<<i<<" ";
  return 0;
}
vector<int> maxOfMin(int arr[], int n)
{
    int left[n],right[n],rang;
    stack<int> S;
    /// finding the nearest_smaller_element_to_left and nearest_smaller_element_to_right using Stack
    for(int i=n-1;i>=0;i--)
    {
        if(S.empty())
            right[i]=n-1;
        else if(arr[S.top()]<arr[i])
            right[i]=S.top()-1;
        else{
            while(!S.empty())
            {
                if(arr[S.top()]<arr[i])
                    break;
                S.pop();
            }
            if(S.empty())
                right[i]=n-1;
            else
                right[i]=S.top()-1;
        }
        S.push(i);
    }
    while(!S.empty())         //emptying stack
        S.pop();
    for(int i=0;i<n;i++)
    {
        if(S.empty())
            left[i]=0;
        else if(arr[S.top()] < arr[i])
            left[i]=S.top()+1;
        else{
            while(!S.empty())
            {
                if(arr[S.top()]<arr[i])
                    break;
                S.pop();
            }
            if(S.empty())
                left[i]=0;
            else
                left[i]=S.top()+1;
        }
        S.push(i);
    }

    vector<int> ans(n,INT_MIN);
    for(int i=0;i<n;i++)
    {
        rang=right[i]-left[i]+1;
        ans[rang-1]=max(ans[rang-1],arr[i]);
    }
    for(int i=n-2;i>=0;i--)
        ans[i]=max(ans[i],ans[i+1]);

    return ans;
}
/*
7
10 20 30 50 10 70 30
Ans: 70 30 20 10 10 10 10

4
2 6 1 12
Ans: 12 2 1 1

7
1 2 3 5 1 13 3
Ans: 13 3 2 1 1 1 1
*/
