//https://www.hackerrank.com/challenges/game-of-two-stacks/problem
#include <iostream>
#include <vector>
using namespace std;
using llt=long long int;

int maxSelections(vector<int> a,vector<int> b,llt maxSum);

int main()
{
    int n,m;
    llt maxSum;
    cin>>n>>m>>maxSum;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    cout<<maxSelections(a,b,maxSum);
  return 0;
}
int maxSelections(vector<int> a,vector<int> b,llt maxSum)      //! T.C.= O(n)
{
    /*
    We'll begin by taking as many integers as possible from stack A without exceeding the sum. Once we've done this we'll start
    taking integers from B, but whenever the sum becomes larger than the limit, we'll put integers back into stack A. Make sure
    to update the answer (the number of integers) as the traversal through stack B takes place. Break the loop when you have put
    back all integers that was taken from A and it's not possible to take any more integers from B.
    */
    int mxcnt,cnt=0,i,j;
    llt sum=0;
    for(i=0;i<a.size();i++)
    {
        if(sum+a[i]>maxSum){
            break;
        }
        sum+=(llt)a[i];
        cnt++;
    }
    mxcnt=cnt;
    i--;
    for(j=0;j<b.size();j++){
        sum+=b[j];
        while(sum>maxSum && i>=0){
            sum-=(llt)a[i];
            i--;
            cnt--;
        }
        if(sum<=maxSum)
            cnt++;
        mxcnt=max(mxcnt,cnt);
    }
    /*while (y < m && x >= 0) {
            sum += B[y++];
            while (sum > ms && x > 0) {
                sum -= A[--x];
            }

            if (sum <= ms && ans < x + y) {
                ans = x + y;
            }
        }*/
    return mxcnt;
}
/*
There is also a O(n*log(n)) approach. Find the cumulative sum for both stacks. Let Pai denote a0+a1+a2+..+ai
and Pbi denote b0+b1+b2+..+bi. Loop over Pa until Pai<=maxSum and binary search on Pb to find how many numbers you can take
from stack B.

The solution below uses this approach:
        cin >> n >> m >> maxSum;
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
			pa[i+1] = pa[i] + a[i];
		}
		for (i = 0; i < m; i++)
		{
			cin >> b[i];
			pbb[i+1] = pbb[i] + b[i];
		}
		int ans = 0;
		for (i = 0; i <= n; i++)
		{
			if (pa[i] <= maxSum)
			   ans = max(ans, i+(int)(upper_bound(pbb, pbb+m+1, maxSum-pa[i])-pbb-1));
			else
				break;
		}
		cout << ans << endl;
*/
