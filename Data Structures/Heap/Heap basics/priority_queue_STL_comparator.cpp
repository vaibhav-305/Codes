#include <iostream>
#include <queue>
#include <utility>
using namespace std;

struct myComp1 {
    bool operator()(pair<int,int> const& a, pair<int,int> const& b)
    {
        return a.second > b.second;   //! The comparator here is written in the opposite way from how comparators are written in sort() i.e. '>' for min heap & '<' for max.
    }
};
struct myComp2 {
    bool operator()(pair<int,int> const& a, pair<int,int> const& b)
    {
        if(a.first==b.first)
            return a.second > b.second;

        return a.first < b.first;
    }
};
void showQ(auto Q)
{
    while(!Q.empty())
    {
        cout<<Q.top().first<<" "<<Q.top().second<<"\n";
        Q.pop();
    }
    cout<<"\n";
}
int main()
{
    //Sample demonstration for priority queue comparator
    priority_queue<pair<int,int>,vector<pair<int,int>>,myComp1> pQ1;
    pQ1.push({2,3});
    pQ1.push({3,3});
    pQ1.push({4,0});
    pQ1.push({3,1});
    pQ1.push({3,0});
    pQ1.push({4,2});
    showQ(pQ1);

    /// Duplicates in priority queue
    priority_queue<pair<int,int>> pQ2;       //prioritizing on the basis of first val in pair
    pQ2.push({2,3});
    pQ2.push({3,3});
    pQ2.push({4,0});
    pQ2.push({3,1});
    pQ2.push({3,0});
    pQ2.push({4,2});
    showQ(pQ2);
    /* Output: 4 2
               4 0        Thus by observing output we can say that
               3 3        it is not compulsory that the whichever came
               3 1        first will come on top(and pop out) first.
               3 0        So to achieve this we can use a custom comparator function.
               2 3        and setting the pair.second val accordingly (smaller to the first pushed ones)
    */
    priority_queue<pair<int,int>,vector<pair<int,int>>,myComp2> pQ3;
    pQ3.push({2,3});
    pQ3.push({3,3});
    pQ3.push({4,0});
    pQ3.push({3,1});
    pQ3.push({3,0});
    pQ3.push({4,2});
    showQ(pQ3);

  return 0;
}
