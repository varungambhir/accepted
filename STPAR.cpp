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
void scanintll(unsigned long long int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int a[1010];
int main()
{
int t,i,need;
scanf("%d",&t);
while(t!=0)
{
    for (i = 0; i < t; ++i)
        scanint(a[i]);
    stack<int> lane;
    need=1;
    bool state=true;
    for (int i = 0; i < t; ++i)
    {
        while(!lane.empty() && lane.top()==need)
            {
                need++;
                lane.pop();
            }
        if(a[i]==need)
        {
            need++;
        }
        else if(!lane.empty() && lane.top()<a[i])
        {
            state=false;
            break;
        }
        else
            lane.push(a[i]);

    }
    if(state)
        printf("yes\n");
    else
        printf("no\n");

    scanf("%d",&t);
}
  return 0;
}
