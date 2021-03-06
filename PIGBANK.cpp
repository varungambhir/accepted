#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define gc getchar_unlocked

#define INF 9999999
#define MAX2 10010
#define MAX1 510
#define MIN(a,b) ((a) < (b) ? (a) : (b))
using namespace std;
int dp[MAX1][MAX2];
int val[501],wt[501];
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int main()
{   int n,s1,wmax,t,i,j;
    scanint(t);
    while(t--)
    {
        scanint(s1);
        scanint(wmax);
        wmax-=s1;
        scanint(n);

        for (i = 1; i <= n; ++i)
        {   dp[i][0]=0;
            scanint(val[i]);
            scanint(wt[i]);
        }
        for (i = 1; i <=n ; ++i)
        {
            for (j = 1; j <=wmax; ++j)
            {
                if(i==1 && j<wt[i])//ie j<wt[1] first weight as it's ascending
                {
                    dp[i][j]=INF;
                }
                else if(i==1)//rest of them
                {
                    dp[i][j]=val[i]+dp[i][j-wt[i]];//for first row
                }
            else if(j<wt[i])//for i >1
            {
                dp[i][j]=dp[i-1][j];
            }
            else // general knapsack
            {
                dp[i][j]=MIN(dp[i-1][j],(val[i]+dp[i][j-wt[i]]));
            }
        }
    }
if(dp[n][wmax]>=INF)
    printf("This is impossible.\n");
  else
printf("The minimum amount of money in the piggy-bank is %d.\n",dp[n][wmax]);
    }
    return 0;
}
