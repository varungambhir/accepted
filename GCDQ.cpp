#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <iterator>
#include <complex>
//#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FF(i,a,n) for(i=(a);i<(n);++i)
#define REP(i,a,n) for(i=(a);i<=(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define matrix vector< vector<ll> >
#define gc getchar_unlocked
#define ft first
#define se second
#define MAXNN 100010
#define mod 10000007
#define INPFILE freopen("input.in","r",stdin)
//ios_base::sync_with_stdio(false);
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
int a[MAXNN],left1[MAXNN],right1[MAXNN];
int gcd(int u, int v)
{
 if(v==1 || u==1)
    return 1;
  int shift;

 // if (!u) return v;
 // if (!v) return u;

  for (shift = 0; ((u | v) & 1) == 0; ++shift) {
         u >>= 1;
         v >>= 1;
  }

  while (!(u & 1))
    u >>= 1;

  do {

       while (!(v & 1))
           v >>= 1;

       if (u > v) {
         int t = v; v = u; u = t;}
       v = v - u;
     } while (v != 0);

  return u << shift;
}
int main()
{
//INPFILE;
 int t,gcdtemp,i,q,l,r,n;
 scanint(t);
 while(t--)
 {
  scanint(n);
  scanint(q);
  FF(i,0,n)
      scanint(a[i]);
  left1[0]=a[0];

    FF(i,1,n)
     left1[i]=gcd(a[i],left1[i-1]) ;

    right1[n-1]=a[n-1];

  for(i=n-2;i>=0;i--)
    right1[i]=gcd(right1[i+1],a[i]);
  while(q--)
  {
    scanint(l);
    scanint(r);
    l-=2;
    if(l>=0 && r<n)
      gcdtemp=gcd(right1[r],left1[l]);
    else if(l>=0 && r>=n)
      gcdtemp=left1[l];
    else if(l<0 && r<n)
      gcdtemp=right1[r];
    else
      gcdtemp=1;
    printf("%d\n",gcdtemp);
  }
 }
  return 0;
}

