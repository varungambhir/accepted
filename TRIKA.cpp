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
#define MAX(a,b) ((a)>(b)?(a):(b))
#define gc getchar_unlocked
ll ABS(ll a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second
#define MAXNN 100010
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
int a[32][32];
int main()
{   
    int n,i,j,m,x,y;
    scanint(n);
    scanint(m);
    scanint(x);
    scanint(y);

    for (i = 1; i <= n; ++i)
    {
      for (j=1;j<=m;j++)
      {
        scanint(a[i][j]);
      }
    }
    for (i = x+1; i <= n; ++i)
      a[i][y]=a[i-1][y]-a[i][y];

    for (j=y+1;j<=m;j++)
      a[x][j]=a[x][j-1]-a[x][j];

    for (i = x+1; i <= n; ++i)
    {
      for (j=y+1;j<=m;j++)
      {
        a[i][j]=std::max(a[i-1][j],a[i][j-1])-a[i][j];
      }
    }

    if(a[n][m]>=0)
      printf("Y %d\n",a[n][m]);
    else
      printf("N\n");
    return 0;
}

