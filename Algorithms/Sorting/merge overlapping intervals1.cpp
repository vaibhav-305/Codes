/*The idea is to sort the intervals in increasing order of their starting time. Then create an empty stack and for each interval,

-> If the stack is empty or the top interval in the stack does not overlap with the current interval, push it into the stack.
-> If the top interval of the stack overlaps with the current interval, merge both intervals by updating the end of the top interval at the ending of the current interval.

Finally, print all non-overlapping intervals present in the stack
*/
//! T.C. = O(n*Log(n))   S.C.= O(n)  S.C. can be reduced to O(1) by using vector for storing output ans vector top as top of stack.
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

void mergeIntervals(vector<pair<int,int>> intervals,int n)
{
    if(n<1)
        return;

    // sort the intervals in increasing order of their starting time (aka first )
    sort(intervals.begin(), intervals.end(), [&](pair<int,int> &p1,pair<int,int> &p2){
        return p1.first < p2.first ;
    });

    // create an empty stack
    stack<pair<int,int>> St;

    // push the first interval to stack
    St.push(intervals[0]);

    // do for each interval
    for(int i=1;i<n;i++)
    {
        // get interval from stack top
        pair<int,int> top = St.top();

        // if current interval is not overlapping with stack top,
        // push it to the stack
        if (top.second < intervals[i].first)
            St.push(intervals[i]);

        // Otherwise update the ending time of top if ending of current
        // interval is more
        else if (top.second < intervals[i].second)
        {
            top.second = intervals[i].second;
            St.pop();
            St.push(top);
        }
    }

    // print all non-overlapping intervals
    while (!St.empty())
    {
        cout << '{' << St.top().first << ", " << St.top().second << "}\n";
        St.pop();
    }
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> intervals(n);
    for(int i=0;i<n;i++)
        cin>>intervals[i].first>>intervals[i].second;

    mergeIntervals(intervals,n);
  return 0;
}
/*
6
1 5
2 3
4 6
7 8
8 10
12 15
Ans: {12, 15} {7, 10} {1, 6}
*/
