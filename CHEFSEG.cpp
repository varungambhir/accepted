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
ll arr[40];
void generate()
{
    for (int i = 0; i < 41; ++i)
    {
        arr[i]=pow(2,i);
    }
}
int main()
{generate();
double ans;
 int t,j;
 scanint(t);
 while(t--)
 {

ll x,k;
scanintll(x);
scanintll(k);
for ( j = 0; j < 41; ++j)
{
    if(k<=arr[j])
        break;
}
if(arr[j]==k)
ans=(x*1.0)/arr[j+1];
else
{
    j--;
    ans=((x*2.0)/arr[j+1])*(k-arr[j]) + (x*1.0)/arr[j+1];;
}
printf("%lf\n",ans);
 }
  return 0;
}
