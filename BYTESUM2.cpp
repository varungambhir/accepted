#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define gc getchar_unlocked
using namespace std;
#define MAX2(a,b)  ((a) > (b) ? (a) : (b))
void scanint(int &x)
{
    register int c = gc();
    x= 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int max(int a, int b, int c)
{
     int m = a;
     (void)((m < b) && (m = b)); 
     (void)((m < c) && (m = c));
     return m;
}
int main()
{  
    int dp[102][102],t,rows,cols,maxi;
    scanint(t);
    while(t--)
    {
        scanint(rows);
        scanint(cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                scanint(dp[i][j]);
        for (int i = 1; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if(!j)
                {
                    dp[i][j]+=MAX2(dp[i-1][0],dp[i-1][1]);
                }
                else if(j==cols-1)
                {
                    dp[i][j]+=MAX2(dp[i-1][j],dp[i-1][j-1]);
                }
                else
                {
                    dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]);
                }
            }
        }
        maxi=dp[rows-1][0];
for (int i = 1; i < cols; ++i)
{
    maxi=(maxi<dp[rows-1][i]?dp[rows-1][i]:maxi);
}
printf("%d\n",maxi);
    }
    return 0;
}
