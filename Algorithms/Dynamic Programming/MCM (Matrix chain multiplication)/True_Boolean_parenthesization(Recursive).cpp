#include <iostream>
using namespace std;

//0 ~ False
//1 ~ True

int main()
{
    string s;

  return 0;
}
int solve(string s, int i, int j, bool isTrue)
{
    if(i>j)
        return 1;  //true

    if(i==j)
    {
        if(isTrue==true)
            return s[i]=='T';
        else
            return s[i]=='F';
    }

    int ans=0;

    for(int k=i+1)
}
