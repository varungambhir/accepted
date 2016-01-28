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
#define MAXNN 10000010
#define mod 10000007
inline void inputfile() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
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
int segment_tree[MAXNN][3],lazzzy[MAXNN][3],stree[MAXNN][3], srr[MAXNN];
int build_tree(int,int,int);
int update_tree(int,int,int,int,int,int);
int query_tree(int,int,int,int,int,int);
char strr[100010];
int main()
{
//ios_base::sync_with_stdio(false);
  inputfile();
  ll op;
 int ind,left,kk,right,i,n,m;
scanint(n);
scanint(m);
scanf("%s",strr);
srr[0]=0;
FF(i,1,(n+1))
srr[i]=srr[i-1]+((int)strr[i-1]-'0')%3;
FF(i,0,3)
build_tree(1,0,n);
while(m--)
{
    scanint(ind);
    scanint(left);
    scanint(right);
    if(ind==1)
    {
        i=(3+right%3 - srr[left]%3)%3;
        update_tree(1,0,n,i,left,n);
    }
    else
    {
        op=0;
        FF(i,0,3)
        {
            kk=query_tree(1,0,n,i,left-1,right);
            op=op+ (kk*(kk-1))/2;
        }
        printf("%lld\n",op);
 
    }
 
}
  return 0;
}
 
int build_tree(int n,int a,int b)
{
    if(a==b)
    {
        F(i,0,3)
            segment_tree[n][i]=lazzzy[n][i]=0;
            segment_tree[n][srr[a]%3]++;
            return 0;
    }
 
int m=a+(b-a)/2;
build_tree(2*n,a,m);
build_tree(2*n+1,m+1,b);
F(i,0,3){
lazzzy[n][i]=0;
segment_tree[n][i]=segment_tree[2*n][i]+segment_tree[2*n+1][i];
}
return 0;
}
int update_tree(int n,int a,int b,int k,int x,int y)
{
if(y<a || x>b)
        return 0;
if(y>=b && a>=x)
{
        F(i,0,3)
        {
            stree[n][i]=segment_tree[n][i];
        }
        F(i,0,3)
        {
            segment_tree[n][i]=stree[n][(k+i+lazzzy[n][i])%3];
        }
        F(i,0,3)
        {
            lazzzy[2*n][i]=lazzzy[2*n][i]+(lazzzy[n][i]+k)%3;
            lazzzy[2*n+1][i]=lazzzy[2*n+1][i]+(lazzzy[n][i]+k)%3;
            lazzzy[n][i]=0;
        }
  return 0;
}
F(i,0,3)
{
    lazzzy[2*n][i]=lazzzy[2*n][i]+lazzzy[n][i]%3;
    lazzzy[1+2*n][i]=lazzzy[1+2*n][i]+lazzzy[n][i]%3;
    lazzzy[n][i]=0;
}
int mid=a+(b-a)/2;
update_tree(2*n,a,mid,k,x,y);
update_tree(1+2*n,mid+1,b,k,x,y);
F(i,0,3)
segment_tree[n][i]=segment_tree[2*n][i]+segment_tree[1+2*n][i];
return 0;
}
int query_tree(int n,int a,int b,int ind,int x,int y)
{
if(a>y || x>b)
    return 0;
if( y>=b && a>=x)
return segment_tree[n][ind];
 
int m=a+(b-a)/2;
int k1=query_tree(2*n,a,m,ind,x,y);
int k2=query_tree(2*n+1,m+1,b,ind,x,y);
 
return (k2+k1);
}