//Approach Link: https://www.youtube.com/watch?v=CZQGRp93K4k&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=83
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> max_in_windows(int * ,int ,int );
vector<int> min_in_windows(int * ,int ,int );

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<int> mx=max_in_windows(arr,n,k);
    vector<int> mn=min_in_windows(arr,n,k);

    cout<<"Maximum in every window: ";
    for(int i: mx)
        cout<<i<<" ";
    cout<<"\nMinimum in every window: ";
    for(int i: mn)
        cout<<i<<" ";
  return 0;
}
vector<int> max_in_windows(int arr[], int n, int k)      //! T.C.= O(n)+O(n)          S.C.= O(k)
{
    vector<int> mx;
    deque<int> Dq;     /// we'll store the elements in decreasing order(5,3,1,-2..) so that our maximum for any window will be Dq.front(), and as we slide , we'll check Dq.front() and arr[i] and if they are equal, we'll remove that occurrence of element (Dq.pop_front()) and i++ (sliding window ahead by one step);
    int i=0,j;

    for(j=0;j<k;j++){                //for first window
        if(Dq.empty() || Dq.back()>=arr[j])       // storing elements in decreasing order
            Dq.push_back(arr[j]);

        else{
            while(!Dq.empty() && Dq.back()<arr[j])
                Dq.pop_back();
            Dq.push_back(arr[j]);
        }
    }

    mx.push_back(Dq.front());     //pushing the max of first window in answer

    while(j<n)       //sliding the window,  here j=k & i=0 before the starting of loop
    {
        if(arr[i]==Dq.front())      //removing the element if it is in Deque but will be in window after sliding
            Dq.pop_front();
        i++;

        while(!Dq.empty() && Dq.back()<arr[j])        //adding arr[j] to back of Deque such that arr[i]<=dq.back(), we'll pop elements until we satisfy this condition or there is no element left in deque.
            Dq.pop_back();
        Dq.push_back(arr[j]);
        j++;

        mx.push_back(Dq.front());
    }
    return mx;
}
vector<int> min_in_windows(int arr[],int n,int k)     //! T.C.= O(n)+O(n)          S.C.= O(k)
{
    vector<int> mn;
    deque<int> Dq;    /// we'll store the elements in decreasing order(-1,2,5,6..) so that our minimum for any window will be Dq.front(), and as we slide , we'll check Dq.front() and arr[i] and if they are equal, we'll remove that occurrence of element (Dq.pop_front()) and i++ (sliding window ahead by one step);
    int i=0,j;

    //here we'll store elements in increasing order.
    for(j=0;j<k;j++)
    {
        while( !Dq.empty() && Dq.back()>arr[j])
            Dq.pop_back();
        Dq.push_back(arr[j]);
    }

    mn.push_back(Dq.front());

    while(j<n)
    {
        if(arr[i]==Dq.front())
            Dq.pop_front();
        i++;

        while( !Dq.empty() && Dq.back()>arr[j])
            Dq.pop_back();
        Dq.push_back(arr[j]);
        j++;

        mn.push_back(Dq.front());
    }
    return mn;
}
/*
8 3
1 3 -1 -3 5 3 6 7
Maximum in every window: 3 3 5 5 6 7
*/
