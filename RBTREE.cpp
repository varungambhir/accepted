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
typedef long long int ll;
#define gc getchar_unlocked
#define FOR(i,n) for(int i=0;i<n;i++)
#define abs(x) ((x)<0 ? -(x) : (x))
#define MAXN 10000010
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
ll getcommon(ll x,ll y)
{
    while(x!=y)
    {
        if(x>y)
            x=x>>1;
        else
            y=y>>1;
    }
    return x;
}
char u,ch;
int main()
{
int t;
bool check=true;//root Black
scanint(t);
while(t--)
{
ll x,y,temp1,dist,comroot;
scanf("%c%c",&u,&ch);
if(ch=='i')
{
if(check==true)
check=false;
else
check=false;
}
else
{
scanintll(x);
scanintll(y);
comroot=getcommon(x,y);
temp1=log2(x);
if(x==y)
dist=0;
else
 dist=1+log2(x)+log2(y)-2*log2(comroot);
cout<<dist<<endl;
        if((dist&1) || dist==0)
        {


        }
        //else
          //  printf("%lld\n",dist/2);

}
}
  return 0;
}
