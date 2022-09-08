#include <iostream>
#include <set>
using namespace std;

void allDivisors(int n)
{
    set<int> S;
    S.insert(1);
    int i;
    for(i=2; i*i<=n; i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)   // If divisors are equal, print only one
                S.insert(i);

            else{     // Otherwise print both
                S.insert(i);
                S.insert(n/i);
            }
        }
    }

    for(int j:S)
        cout<<j<<" ";
}

int main()
{
    int n;
    cin>>n;
    allDivisors(n);
    return 0;
}
