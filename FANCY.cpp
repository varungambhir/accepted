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
char s[32];
int main()
{   
    int t,i;
    scanint(t);
    while(t--)
    {
      scanf("%s",s);
      int cntseq[40],k=0;
      for (i = 0; s[i]!='\0'; ++i)
      {
        if(!i)
        {
          memset(cntseq,0,sizeof(cntseq));
          continue;
        }
        else if(s[i]==s[i-1])
        {
          cntseq[k]++;
        }
        else
          k++;

      }
      //printf("dsd\n");
      long long ans=1;
      for (i = 0; i <= k; ++i)
      {
        ans*=(pow(2,cntseq[i]));
      }
      printf("%lld\n",ans);

    }
    return 0;
}

