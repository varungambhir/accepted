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
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define gc getchar_unlocked
#define MODU 1000000007
#define MAXN 2000
#define abs(x)  ( ( (x) < 0) ? (-x) : (x) )
using namespace std;

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
{
    int t,a[1005],min,k,b[1005],n,m;
    scanint(t);
    while(t--)
    {
        scanint(n);
        for (int i = 0; i < n; ++i)
        {
            scanint(a[i]);
        }
        scanint(m);
        for (int i = 0; i < m; ++i)
        {
            scanint(b[i]);
        }
        min= 1000010;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {   k=(a[i]-b[j]);
                k=abs(k);
                if(k==0)
                {
                    min=0;
                    break;
                }
                else if(k<min)
                {
                    min=k;
                }
            }
            if(min==0)break;
        }
    printf("%d\n",min);
    }
    return 0;
}
