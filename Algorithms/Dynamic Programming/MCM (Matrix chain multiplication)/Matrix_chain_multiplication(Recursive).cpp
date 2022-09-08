/*
Problem statement
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.
We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product, the result will be the same.

For example, if we had four matrices A, B, C, and D, we would have:
(ABC)D = (AB)(CD) = A(BCD) = ....
However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency. For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,

(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.
Clearly the first parenthesization requires less number of operations and thus is the answer.
*/
#include <iostream>
using namespace std;

int MatrixChainOrder(int *,int , int );

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<MatrixChainOrder(arr,1,n-1);     //as in answer we are using arr[i-1] and if i=0 then it it would be invalid index(arr[-1]) so we send 1 index for i and n-1 index(rightmost) for j.

  return 0;
}

int MatrixChainOrder(int arr[],int i, int j)      //function which gives min cost of multiplication
{
    if (i >= j)
        return 0;

    int Min = INT_MAX;
    int temp_ans;

    // place parenthesis at different places
    // between first and last matrix, recursively
    // calculate cost of multiplications for
    // each parenthesis placement and return the
    // minimum cost
    for (int k = i; k <= j-1; k++)
    {
        temp_ans = MatrixChainOrder(arr, i, k)+MatrixChainOrder(arr, k + 1, j)+arr[i - 1]*arr[k]*arr[j];

        if (temp_ans < Min)
            Min = temp_ans;
    }

    // Return minimum cost of multiplication
    return Min;
}
/// Time complexity(Recursive method): exponential
/*
Dataset
5
40 20 30 10 30            ans: 26000 order: ((A(BC))D)
*/
