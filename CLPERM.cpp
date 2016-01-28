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
#define pb push_back
#define mp make_pair
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
std::vector<long long int> vi;

int main()
{
  //INPFILE;
 ll i,t,n,k,sum,temp,pre;
 scanintll(t);
 while(t--)
{
  vi.clear();
  scanintll(n);scanintll(k);
  if(!k)
  {
      sum=(n*(n+1))/2;
      if(sum&1)
        printf("Mom\n");
      else
        printf("Chef\n");
  }
  else{
  FF(i,0,k)
  {scanintll(temp);vi.pb(temp);}
  sort(vi.begin(), vi.end());
    temp=pre=0;
    FF(i,0,k)
    {
      sum=vi[i]-1;
      sum=(sum*(sum+1))/2 -temp;
      if(sum<vi[i]) break;
      temp =temp+vi[i];
      pre=vi[i];
    }
    if(!pre)
      pre=vi[0]-1;
    if(i<k)
    {
      if(pre&1)
        printf("Mom\n");
      else
        printf("Chef\n");
    }
    else
    {
      sum=(vi[k-1]*(vi[k-1]+1))/2 -temp;
      if(sum<vi[k-1]+1)
      {
        if(vi[k-1]&1)
          printf("Mom\n");
          else
            printf("Chef\n");
      }
      else
      {
        sum=(n*(n+1))/2-temp;
        if(sum&1)
          printf("Mom\n");
        else
          printf("Chef\n");
      }

    }



      }

}

  return 0;
}

