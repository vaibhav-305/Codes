/* let n = (p1^e1)*(p2^e2)*.....*(pN^eN)   <-- prime factorization of n
Then total number of divisors of n = (e1+1)*(e2+1)*...*(eN+1)
*/
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

long long int NumOfDivisor(int);

int main()
{
    int n;
    cin>>n;
    cout<<NumOfDivisor(n);
  return 0;
}
vector<pair<int,int>> primeFactorization(int n)                  /// T.C.=O(sqrt(n))
{
    int cnt=0;
    vector<pair<int,int>> primefact;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            cnt=0;
            while(n%i==0)
            {
                cnt++;
                n=n/i;
            }
            primefact.push_back(make_pair(i,cnt));
        }
    }
    //if no. is prime
    if(n>1)
        primefact.push_back(make_pair(n,1));

    return primefact;
}
long long int NumOfDivisor(int n)
{
    long long int ans=1;
    vector<pair<int,int>> primefact = primeFactorization(n);
    for(pair<int,int> p:primefact)
    {
        ans*=(p.second+1);
    }
    return ans;
}
