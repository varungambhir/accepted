#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define gc getchar_unlocked
#define MAXN 10005
using namespace std;
#define MAX(a,b)  ((a) > (b) ? (a) : (b))
void scanint(long long int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
long long int a[MAXN],dp[MAXN];
int main()
{
   long long int t,n,i;
    scanint(t);
    for(int z=1;z<=t;z++)
    {
        scanint(n);
        if(!n){
        printf("Case %d: 0\n",z);
        }
        else
        {
        for (i = 0; i < n; ++i)
        scanint(a[i]);

        dp[0]=a[0];
        dp[1]=MAX(a[1],dp[0]);
        for (i = 2; i < n; ++i)
        {
            dp[i]=MAX(a[i]+dp[i-2],dp[i-1]);
        }

        printf("Case %d: %lld\n",z,dp[n-1]);
        }
    }
    return 0;
}
