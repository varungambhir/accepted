#include <bits/stdc++.h>
using namespace std;


//this is way too easy for even a basic google question
int main(int argc, char const *argv[])
{
    int arr[101]= {0};
    arr[10] = 1;// not present
    arr[1] = 1;
    arr[22] = 1;
    arr[23] = 1;
    arr[22] = 1;
    arr[25] = 1;
    arr[26] = 1;
    arr[99] = 1;
    int st = 1;
    for (int i = 0; i < 101; ++i)
    {
        if(arr[i] == 1)//not present
        {
            cout << i << " - ";                
            while(arr[i] == 1)
                i++;
            cout << --i << "\n";
        }
    }


    return 0;
}