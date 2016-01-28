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
int godz[MAXN],mechgodz[MAXN];
int main()
{
  int j,t,g,mg,i;
  scanint(t);
  while(t--)
  {
    scanint(g);
    scanint(mg);
    for ( i = 0; i < g; ++i)
    scanint(godz[i]);
    for ( i = 0; i < mg; ++i)
    scanint(mechgodz[i]);
    std::sort(godz,godz+g);
    std::sort(mechgodz,mechgodz+mg);
    i=g-1;
    j=mg-1;
    while(i>-1 && j>-1)
    {
      if(godz[i]>=mechgodz[j])
        j--;
      else
      i--;
    }
    if(i>-1)
    printf("Godzilla\n");
    else
    printf("MechaGodzilla\n"); 
  }
  return 0;
} 
