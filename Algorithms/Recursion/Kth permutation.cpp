/* Problem:
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
Given n and k, return the kth permutation sequence.
1 <= k <= n!
1<=n<=9
*/
//! T.C.= O(n*n)       S.C.= O(n)
#incude <iostream>
#include <list>
using namespace std;

string Kth_permutation(int , int );

int main() {
	//code
	int n,k;
	cin>>n>>k;
	cout<<Kth_permutation(n,k);
	return 0;
}
int getnum(int indx, list<int>& L)
{
    int i=0,val;
    for(auto itr=L.begin();itr!=L.end();itr++)
    {
        if(i==indx)
        {
            val=*itr;
            L.erase(itr);
            return val;
        }
        i++;
    }
    return -1;
}
string Kth_permutation(int n, int k)
{
    if(n==1)
        return "1";

    list<int> L;
    int fact[n+1];
    fact[1]=1;
    L.push_back(1);
    for(int i=2;i<=n;i++){
        L.push_back(i);
        fact[i]=fact[i-1]*i;
    }

    string str;
    int quo;
    while(k)
    {
        quo=k/fact[n-1];
        k-=quo*fact[n-1];
        if(k==0)
        {
            str.push_back(getnum(quo-1,L)+'0');
            break;
        }
        str.push_back(getnum(quo,L)+'0');
        n--;
    }
    for(auto i=L.rbegin();i!=L.rend();i++){
        //cout<<*i<<" ";
        str.push_back(*i+'0');
    }
  return str;
}
