#include <bits/stdc++.h>
using namespace std;

/*
    C(n,r) mod m
    Using recurrence:
    C(i,k) = C(i-1,k-1) + C(i-1,k)
    Time Complexity: O(n*r)
    Space Complexity: O(n*r)
*/

long long int Calc(int n,int r,int m)
{
    vector< vector<long long> >C(n+1,vector<long long>(r+1,0) );

    for (int i = 0; i <=n; ++i)
    {
        for(int k = 0; k <=min(i,r); k++)
        {
            if(k == 0 || k == i )
            {
                C[i][k] = 1;
                cout << i << " " << k << C[i][k] << endl;
            }
            else
            {
                C[i][k] = (C[i-1][k] + C[i-1][k-1])%m;
                cout << i << " " << k << C[i][k] << endl;
            }
        }
    }
    return C[n][r];
}

int main()
{
    int n,r,m;
    while(cin >> n >> r >> m)
    {
        printf("%lld\n",Calc(n,r,m));
    }
}