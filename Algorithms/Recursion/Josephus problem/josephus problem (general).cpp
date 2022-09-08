/*
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle.
The task is to choose the place in the initial circle so that you are the last one remaining and so survive.
*/
//! T.C.= O(n*n)   as erase() function takes log(n) time
#include <iostream>
#include <vector>
#include <ex
using namespace std;

void Josh(vector<int>& person, int k, int index)
{
    // Base case , when only one person is left
    if (person.size() == 1) {
        cout << person[0] << endl;
        return;
    }

    // find the index of person which will die
    index = ((1ll*index + k) % person.size());
    cout<<person[index]<<" ";

    // remove the person which is going to be killed
    person.erase(person.begin() + index);

    // recursive call for n-1 persons
    Josh(person, k, index);
}
int lastPersonJosephus(int n,int k)
{
    vector<int> person;
    for(int i=1;i<=n;i++)
        person.push_back(i);

    k--; // (k-1)th person will be killed as 0 based indexing in vector
    int index = 0; // The index where the person which will die

    Josh(person, k, index);
}
int main()
{
    int n,k;
    cin>>n>>k;
    lastPersonJosephus(n,k+1);
  return 0;
}
