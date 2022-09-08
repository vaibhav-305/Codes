#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct Job      // A structure to represent a job
{
   int id;      // Job Id
   int dead;    // Deadline of job
   int profit;  // Profit if job is over before or on deadline
};

int jobScheduling(Job arr[],int n);

int main()
{
    int n;
    cin>>n;
    Job arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i].id>>arr[i].dead>>arr[i].profit;

    cout<<jobScheduling(arr,n);
  return 0;
}

/// Standard method
//! T.C.= O(n*log(n))+O(maxSlot*maxSlot)         S.C.= O(maxSlot)
int jobScheduling(Job arr[],int n)
{
    int maxSlot=arr[0].dead;
    for(int i=1;i<n;i++)
        maxSlot=max(maxSlot,arr[i].dead);

    sort(arr,arr+n, [&](Job &a, Job &b){
         return a.profit>b.profit;
    });

    int res[maxSlot];
    memset(res,-1,sizeof(res));

    int Profit=0,jobcount=0;

    for(int i=0;i<n;i++)
    {
        for(int j=arr[i].dead-1 ; j>=0 ; j--)
        {
            if(res[j]==-1)      //-1 means interval is empty
            {
                res[j]=arr[i].id;  //filling the first encountered (i.e. rightward/endLimit)
                jobcount++;
                Profit+=arr[i].profit;
                break;
            }
        }
    }
    for(int i=0;i<maxSlot;i++)
    {
        if(res[i]!=-1)
            cout<<res[i]<<" ";
    }
    cout<<"\n";
    return Profit;
}
/*
5
1 2 100
2 1 19
3 2 27
4 1 25
5 3 15
*/
