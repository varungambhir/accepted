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
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define gc getchar_unlocked
ll ABS(ll a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second
#define MAXNN 21000
#define mod 10000007
void inputfile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}

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

int ind[MAXNN],arr[MAXNN],rank[MAXNN];
inline void func()
{
for(int i=0; i<MAXNN; i++)  
{
    ind[i] = i;
    rank[i] = 0;
}
memset(arr,-1,sizeof(arr));
}
int find(int x)
{
    if (ind[x]!=x)
    {
        ind[x]=find(ind[x]);
    }
    return ind[x];
}
void Union(int x,int y)
{
    int xroot,yroot;
    xroot=find(x);
    yroot=find(y);
    if(xroot==yroot)
        return;
    if(rank[xroot]<rank[yroot])
        ind[xroot]=ind[yroot];
    else if(rank[xroot]>rank[yroot])
        ind[yroot]=ind[xroot];
    else
    {   
        ind[yroot]=ind[xroot];
        rank[xroot]=rank[xroot]+1;
    }
}
int main()
{
  int i,n,m,x,y,flag=0;
  scanint(n);
  scanint(m);
  func();
  FF(i,0,m)
  {
    scanint(x);
    scanint(y);
    if(find(x)!=find(y))
    Union(x,y);
    else
    flag=1;
  }
  if(flag)
  printf("NO\n"); 
else
    printf("YES\n");
  return 0;
}

