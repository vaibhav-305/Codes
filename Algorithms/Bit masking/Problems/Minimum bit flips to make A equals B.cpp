#include <iostream>
using namespace std;

int main()
{
    int A,B;
    cin>>A>>B;

    int Xor= (A ^ B);

    //set bits in Xor is the answer
    int rsb,cnt=0;
    while(Xor!=0)
    {
        rsb=(Xor & -Xor);
        Xor=Xor-rsb;
        cnt++;
    }

    cout<<cnt<<endl;
  return 0;
}
