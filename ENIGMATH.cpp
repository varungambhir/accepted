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
typedef unsigned long long int ull;
#define gc getchar_unlocked
#define FOR(i,n) for(int i=0;i<n;i++)
#define abs(x) ((x)<0 ? -(x) : (x))
#define MAXN 10000010
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

ull gcd(ull u,ull v)
{
  int shift;
 
  /* GCD(0,v) == v; GCD(u,0) == u, GCD(0,0) == 0 */
  if (u == 0) return v;
  if (v == 0) return u;
 
  /* Let shift := lg K, where K is the greatest power of 2
        dividing both u and v. */
  for (shift = 0; ((u | v) & 1) == 0; ++shift) {
         u >>= 1;
         v >>= 1;
  }
 
  while ((u & 1) == 0)
    u >>= 1;
 
  /* From here on, u is always odd. */
  do {
       /* remove all factors of 2 in v -- they are not common */
       /*   note: v is not zero, so while will terminate */
       while ((v & 1) == 0)  /* Loop X */
           v >>= 1;
 
       /* Now u and v are both odd. Swap if necessary so u <= v,
          then set v = v - u (which is even). For bignums, the
          swapping is just pointer movement, and the subtraction
          can be done in-place. */
       if (u > v) {
        ull t = v; v = u; u = t;}  // Swap u and v.
       v = v - u;                       // Here v >= u.
     } while (v != 0);
 
  /* restore common factors of 2 */
  return u << shift;
}
int main()
{
int t;
ull a,b,ans,x,y;
scanint(t);
while(t--)
{
    scanintll(a);
    scanintll(b);
    ans=gcd(a,b);
    y=a/ans;
    x=b/ans;
    printf("%llu %llu\n",x,y);
}
  return 0;
}
