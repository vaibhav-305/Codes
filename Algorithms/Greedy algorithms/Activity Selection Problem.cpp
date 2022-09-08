//! T.C.= O(n*log(n))          S.C.= O(n)        where n is no. of activities
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_number_of_activities(int *,int *,int);

int main()
{
    int n,start,endi;
    cin>>n;
    int starting[n],ending[n];
    for(int i=0;i<n;i++)
        cin>>starting[i];

    for(int i=0;i<n;i++)
        cin>>ending[i];

    cout<<max_number_of_activities(starting,ending,n);
  return 0;
}
int max_number_of_activities(int starting[],int ending[], int n)
{
    int previous;

    vector<vector<int>> vec;
    for(int i=0;i<n;i++)
    {
        vec.push_back({starting[i], ending[i], i+1});        //if we also want to print the order of activites then we also consider the numbering (i+1)
    }

    sort(vec.begin(), vec.end(), [&](vector<int> &a, vector<int> &b){        //! comparator is defined using lambda function
         return a[1]<b[1];             //we will sort according to ending timing. The reason is we want to know which meeting finishes early and subsequently next meeting.
    });

    int cnt=1;                    //cnt=1 as min. one meeting will happen for n>0
    previous=vec[0][1];
    cout<<vec[0][2]<<" ";         //this(first meeting) will happen so cnt=1
    for(int i=1;i<n;i++)
    {
        if(previous<vec[i][0]){          //the next starting time should be greater(or equal to) than the previous ending time.
            cnt++;
            previous=vec[i][1];
            cout<<vec[i][2]<<" ";
        }
    }
    cout<<endl;
    return cnt;
}
/*
Input:
    N = 6
    start[] = {1,3,0,5,8,5}
    end[] =  {2,4,6,7,9,9}
Output:
    4

8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252
Ans: 3  (6,7,1)
*/
