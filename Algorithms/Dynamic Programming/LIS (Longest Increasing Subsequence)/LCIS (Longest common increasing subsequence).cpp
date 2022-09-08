#include <iostream>
#include <string>
using namespace std;

int LCIS(int *,int *,int ,int ,int ,int ,int );

int main()
{
    int n,m;
    cin>>n>>m;
    int seq1[n],seq2[m];
    for(int i=0;i<n;i++)
        cin>>seq1[i];
    for(int i=0;i<m;i++)
        cin>>seq2[i];
    cout<<LCIS(seq1,seq2,n,m,0,0,INT_MIN);
  return 0;
}

int LCIS(int seq1[],int seq2[],int n,int m,int curr1,int curr2,int prev)
{
    if(curr1==n || curr2==m)
        return 0;

    int incl=0;
    if(seq1[curr1]==seq2[curr2] && prev<=seq1[curr1])
    {
        //cout<<curr1<<" "<<curr2<<"-"<<seq1[curr1]<<" "<<seq2[curr2]<<"\n";
        incl=1+LCIS(seq1,seq2,n,m,curr1+1,curr2+1,seq1[curr1]);
    }

    int excl=max(LCIS(seq1,seq2,n,m,curr1+1,curr2,prev),LCIS(seq1,seq2,n,m,curr1,curr2+1,prev));

    return max(incl,excl);
}
