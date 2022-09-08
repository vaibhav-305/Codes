//problem Link: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int find_celeb(vector<vector<int>>& , int );
int find_celebrity(vector<vector<int>>& ,int );        /// More optimized

int main()
{
    int N;
    cin>>N;
    vector<vector<int>> arr(N, vector<int>(N));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>arr[i][j];

    cout<<find_celeb(arr,N)<<"\n";
    cout<<find_celebrity(arr,N);        //space optimized
  return 0;
}
int find_celeb(vector<vector<int>>& arr, int N)        //! T.C.= O(N)  (not N*N)        S.C.= O(N)
{
    stack<int> S;
    for(int i=0;i<N;i++)
        S.push(i);             //all memebers of party are pushed in stack;

    int a,b;
    while(S.size()>=2)           //we'll pop elements from stack until there is only one element remaining in stack
    {
        a=S.top();
        S.pop();
        b=S.top();
        S.pop();

        if(arr[a][b]==1)          //if arr[a][b]=1 => a knows b => a cannot be celebrity
            S.push(b);
        else                      //if arr[a][b]=0 => a doesn't know b => b cannot be a celebrity
            S.push(a);
    }

    int potential_celeb=S.top();          //only one element will be left in stack which MAY be the celebrity.
    S.pop();
    // Now we'll check if everyone knows that celebrity by traversing arr[i][potential_celeb] and traverse the row of potential_celeb (arr[potential_celeb][i] to confirm that he doesn't know anyone)
    for(int i=0;i<N;i++)
    {
        if(arr[potential_celeb][i]==1)          //this means potential_celebrity knows someone so no celebrity exists in party
            return -1;

        if(potential_celeb!=i  && arr[i][potential_celeb]==0)       //someone still doesn't know potential potential_celeb so no celebrity exists
            return -1;
     }
  return potential_celeb;
}
int find_celebrity(vector<vector<int>>& arr, int N)         //! T.C.= O(N)  (not N*N)        S.C.= O(1)
{
    //Here we'll do the same thing we did in stack approach except we'll not use extra space.
    int temp;
    if(arr[N-1][N-2]==1)          //if arr[N-1][N-2]=1 => (N-1)th knows (N-2)th person => (N-1)th person cannot be celebrity
        temp=N-2;
    else                      //if arr[N-1][N-2]=0 => (N-1)th doesn't know (N-2)th person => (N-2)th person cannot be a celebrity
        temp=N-1;

    for(int i=N-3;i>=0;i--)           //then we'll traverse the array in reverse staring from N-3 and each time check for (i,temp) and update temp accordingly
    {
        if(arr[i][temp]==1)
            temp=temp;
        else
            temp=i;
    }

    int pot_celeb=temp;
    // Now we'll check if everyone knows that celebrity by traversing arr[i][potential_celeb] and traverse the row of potential_celeb (arr[potential_celeb][i] to confirm that he doesn't know anyone)
    for(int i=0;i<N;i++)
    {
        if(arr[pot_celeb][i]==1)          //this means potential_celebrity knows someone so no celebrity exists in party
            return -1;

        if(pot_celeb!=i  && arr[i][pot_celeb]==0)       //someone still doesn't know potential potential_celeb so no celebrity exists
            return -1;
     }
  return pot_celeb;
}
/*
A single person might know others. eg:-
18
0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0
Ans= 12
*/
