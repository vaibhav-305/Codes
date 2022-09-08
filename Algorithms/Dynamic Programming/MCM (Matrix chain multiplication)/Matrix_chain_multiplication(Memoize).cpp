/// Time: O(n*n*n)   space: n*n
//for prob statement look at MCM(Recursive)
#include <iostream>
#include <vector>
using namespace std;

int MatrixChainOrder(int *,int , int , vector<vector<int>>& );

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<vector<int>> memo(n+1, vector<int> (n+1,-1));
    cout<<MatrixChainOrder(arr,1,n-1,memo);     //as in answer we are using arr[i-1] and if i=0 then it it would be invalid index(arr[-1]) so we send 1 index for i and n-1 index(rightmost) for j.

  return 0;
}

int MatrixChainOrder(int arr[],int i, int j, vector<vector<int>>& memo)      //function which gives min cost of multiplication
{
    if (i >= j)
        return 0;

    if(memo[i][j]!=-1)
        return memo[i][j];

    int Min = INT_MAX;
    int temp_ans;

    // place parenthesis at different places
    // between first and last matrix, recursively
    // calculate cost of multiplications for
    // each parenthesis placement and return the
    // minimum cost
    for (int k = i; k <= j-1; k++)
    {
        temp_ans = MatrixChainOrder(arr, i, k,memo)+MatrixChainOrder(arr, k + 1, j, memo)+arr[i - 1]*arr[k]*arr[j];

        if (temp_ans < Min)
            Min = temp_ans;
    }

    // Return minimum cost of multiplication
    memo[i][j]=Min;
    return memo[i][j];
}
/*
Dataset
5
40 20 30 10 30            ans: 26000 order: ((A(BC))D)

5
10 20 30 40 30            ans: 30000 order: ((AB)C)D
*/
