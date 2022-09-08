#include<bits/stdc++.h>
using namespace std;

int main()
{
    // initializing vector of integers
    // for single occurrence
    vector<int> arr1 = {10, 15, 20, 25, 30, 35};

    // initializing vector of integers
    // for multiple occurrences
    vector<int> arr2 = {10, 15, 20, 20, 25, 30, 35};

    // initializing vector of integers
    // for no occurrence
    vector<int> arr3 = {10, 15, 25, 30, 35};
    int a,b,c;


    // using upper_bound() to check if 20 exists
    // single occurrence
    // prints 3
    cout << "The position of 20 using upper_bound"
           " (in single occurrence case) : ";
    a=upper_bound(arr1.begin(), arr1.end(), 36)
        - arr1.begin();
    cout << a;

    cout << endl;

    // using upper_bound() to check if 20 exists
    // multiple occurrence
    // prints 4
    cout << "The position of 20 using upper_bound "
             "(in multiple occurrence case) : ";
    cout << upper_bound(arr2.begin(), arr2.end(), 20)
            - arr2.begin();

    cout << endl;

    // using upper_bound() to check if 20 exists
    // no occurrence
    // prints 2 ( index of next higher)
    cout << "The position of 20 using upper_bound"
            " (in no occurrence case) : ";
    cout << upper_bound(arr3.begin(), arr3.end(), 5)
           - arr3.begin();

    cout << endl;
}
