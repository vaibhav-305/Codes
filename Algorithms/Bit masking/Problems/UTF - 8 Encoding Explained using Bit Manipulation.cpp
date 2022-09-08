/*
Problem link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/bit-manipulation/utf-8-encoding-official/ojquestion
video link: https://www.youtube.com/watch?v=3zyxpFPKkEU&list=PL-Jc9J83PIiFJRioti3ZV7QabwoJK6eKe&index=16
UTF-8 encoding

    character range     |  Byte 1  |  Byte 2  |  Byte 3  |  Byte 4
   ---------------------+----------+----------+----------+------------
         0 - 127        | 0xxxxxxx |          |          |             (needs 1 byte to store)
       128 - 2,407      | 110xxxxx | 10xxxxxx |          |             (needs 2 byte to store)
     2,408 - 65,535     | 1110xxxx | 10xxxxxx |	10xxxxxx |             (needs 3 byte to store)
    65,536 - 11,14,111  | 11110xxx | 10xxxxxx | 10xxxxxx | 10xxxxxx    (needs 4 byte to store)

*/
#include <iostream>
using namespace std;

bool solution(int *, int );

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    if(solution(arr, n))
        cout<<"Yes";
    else
        cout<<"No";

  return 0;
}

bool solution(int arr[], int n)
{
    int rbytes = 0,val;          //remaining bytes

    for(int i=0;i<n;i++)
    {
        val=arr[i];

        if(rbytes==0){
            if((val>>7)==0b0)       //first byte of 1 length char in UTF-8 encoding
                rbytes=0;
            else if((val>>5)==0b110)
                rbytes=1;
            else if((val>>4)==0b1110)
                rbytes=2;
            else if((val>>3)==0b11110)
                rbytes=3;
        } else {
            if((val>>6)==0b10)
                rbytes--;
            else
                return false;
        }
    }

    if(rbytes==0)
        return true;
    else
        return false;
}
