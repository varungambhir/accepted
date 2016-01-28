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
int arr[1100][1100];
int rec(int h,int a,int count,bool flag)
{
if(h<=0 || a<=0)
    return count;
if(arr[h][a])
    return arr[h][a];
if(flag)
    arr[h][a]=max(arr[h][a],rec(h+3,a+2,count+1,!flag));
else
    arr[h][a]=max(arr[h][a],max(rec(h-5,a-10,count+1,!flag),rec(h-20,a+5,count+1,!flag)));
return arr[h][a];
}
int main()
{
int t,h,a,count,flag;
scanf("%d",&t);
while(t--)
{
   scanint(h);
   scanint(a);
   memset(arr,0,sizeof(arr))
   printf("%d\n",rec(h,a,-1,1);
 } return 0;
}

