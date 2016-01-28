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

long long max_area(long long hist[],int n)
{
long long maxarea=0,area_calc;
int i=0,tp;
stack<int> s;
while(i<n)
{
  if(s.empty() || hist[s.top()]<=hist[i])
  {
    s.push(i++);
  }
else
{
  tp=s.top();
  s.pop();
                                    //s.top is next smallest after tp  
  area_calc=hist[tp]*(s.empty()?i:i-1-s.top());

  if(maxarea<area_calc)
    maxarea=area_calc;
}

}

while(s.empty()==false)
{
  tp=s.top();
  s.pop();
                                    //s.top is next smallest after tp  
  area_calc=hist[tp]*(s.empty()?i:i-1-s.top());

  if(maxarea<area_calc)
    maxarea=area_calc;
}
return maxarea;
}

int main()
{ 
  int n;
  long long arr[100005];
  while(S(n) && n!=0)
  {
    for (int i = 0; i < n; ++i)
    {
      scanintll(arr[i]);
    }
    long long ans=max_area(arr,n);
    printf("%lld\n",ans);    

  }

    return 0;
}

