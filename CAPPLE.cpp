#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <stack>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
typedef unsigned long long int ull;
#define gc getchar_unlocked
#define FOR(i,n) for(int i=0;i<n;i++)
#define abs(x) ((x)<0 ? -(x) : (x))
#define MAXN 100010
//#define SPEEDY ios::sync_with_stdio(false); cin.tie(0);
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
void scanintll(long long int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int arr[100002],cnt[100002];
int main()
{
    int count,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanint(n);
        memset(cnt,0,sizeof(cnt));
        count=0;
        for (int i = 0; i < n; ++i)
            {
                scanint(arr[i]);
                if(cnt[arr[i]]==0)
                {
                    cnt[arr[i]]++;
                    count++;
                }
            }
        printf("%d\n", count);
    }
	return 0;
}
