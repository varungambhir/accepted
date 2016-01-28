#include <bits/stdc++.h>
using namespace std;
#define sn struct node
#define R 3
#define C 6

void spiralPrint(int m,int n,int a[][7])
{
    int k,l,i,j;
    //r //c
    k =  l = 1;

    while(k<= m && l<= n)
    {
        for(i = l ; i<= n ; i++)
        {
            cout << a[k][i] << " ";
        }
        k++;

        for(i = k ; i<=m; i++ )
        {
            cout << a[i][n] << " ";

        }
        n--;

        if( k <= m)
        {
            for(i = n; i >= l; i--)
            {
                cout << a[m][i] << " ";
            }
            m--;
        }

        if(l <= n)
        {
            for(i = m; i>=k; i--)
            {
                cout << a[i][l] << " ";
            }
            l++;
        }
    }

}

int main()
{
    int a[][7] = { {0,0,0,0,0,0,0},
    {0,1,  2,  3,  4,  5,  6},
    {0,7,  8,  9,  10, 11, 12},
    {0,13, 14, 15, 16, 17, 18}
};

spiralPrint(R, C, a);
return 0;
}
