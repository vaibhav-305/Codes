//! T.C.= O(log(max(a,b)))
/// note that this code does not consider the degenerate case (a = b = 0). It needs to be checked manually
#include <iostream>
using namespace std;

int gcdExtended(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcdExtended(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x, int &y) {
    int x0,y0;
    int g = gcdExtended(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x = x0 * c / g;
    y = y0 * c / g;
    //The idea still works when a or b or both of them are negative. We only need to change the sign of  and  when necessary.
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return true;
}
int main()
{
    int a,b,c,x,y;
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;
    cout<<"c: ";
    cin>>c;
    if(find_any_solution(a,b,c,x,y))
        cout<<"x = "<<x<<"\ty = "<<y;
    else
        cout<<"No integral solution exists";

  return 0;
}
/*
a: 4
b: 8
c: 7
Ans: No integral soln exists

a: 2
b: 3
c: 10
Ans: x=-10  y=10
*/
