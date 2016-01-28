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
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,n) for(int i=0;i<=n;i++)
#define MAXN 1000001
using namespace std;
#define MAX(a,b)  ((a) > (b) ? (a) : (b))
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
int i,a[10002],t,n;
scanint(t);
while(t--)
{
    scanint(n);
    FOR(j,n){
    scanint(a[j]);}
    if(n==1 && a[0]==0)
    {printf("YES\n");continue;}
    if (n==1 && a[0]!=0)
    {printf("NO\n");continue;}
    if(a[0]>a[1])
    {printf("NO\n");
    continue;}
    
        for (i = 0; (i+1)<n;)
        {
            while(a[i]>0 && a[i+1]>0)
            {   
                a[i]--;
                a[i+1]--;
            }
            if(a[i]==0 && a[i+1]>0)
                    i++;
            else if(a[i]==0 && a[i+1]==0)
                i=i+2;
            else if(a[i]>0 && a[i+1]==0)
                {printf("NO\n");
                    break;}
        }
        for(i=0;i<n;i++)
            if(a[i]!=0)
                {printf("NO\n");break;}
        if(i>=n)
            printf("YES\n");
}    
return 0;
}