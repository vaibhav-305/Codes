//! link: https://www.youtube.com/watch?v=VdQuwtEd10M
#include <iostream>
#include <stack>
using namespace std;

int longest_valid_parantheses(string );

int main()
{
    string s;
    cin>>s;      // s can only contain ')' and '(' characters
    cout<<longest_valid_parantheses(s);
  return 0;
}
int longest_valid_parantheses(string s)       //! S.C.= T.C.= O(n)
{
    /* In order to do so, we start by pushing -1 onto the stack. For every '(' encountered, we push its index onto the stack.

    For every ')' encountered, we pop the topmost element. Then, the length of the currently encountered valid string of
    parentheses will be the difference between the current element's index and the top element of the stack.

    If, while popping the element, the stack becomes empty, we will push the current element's index onto the stack. In this
    way, we can continue to calculate the length of the valid substrings and return the length of the longest valid string at
    the end. */
    int sz=0,mxsz=0;
    stack<int> St;      //for storing index of characters
    St.push(-1);
    for(int i=0;i<s.length();i++){
        if(s[i]=='(')
            St.push(i);
        else{
            St.pop();
            if(St.empty())
                St.push(i);
            else{
                sz=i-St.top();       //current index - index at top of stack
                mxsz=max(mxsz,sz);
            }
        }
    }
    return mxsz;
}
/*
))(()()(
()()()
()()()))))()()()
*/
