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
#define MAXN 1000010
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

int main()
{
  while (1)
  {
    int n;
    scanint(n);
    if (!n)
      break;
    int a[n+1],b[n+1],i,flag=1;
    for (i=1;i<=n;i++)
      scanint(a[i]);
    for (i=1;i<=n;i++)
      b[a[i]]=i;
    for (i=1;i<=n;i++)
    {
      if (a[i]!=b[i])
      {
        flag=0;
        break;
      }
    }
    if (flag)
      printf("ambiguous\n");
    else
      printf("not ambiguous\n");
  }
  return 0;
} 
