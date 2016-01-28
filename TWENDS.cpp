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
#include <sstream>
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
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define all(c) c.begin(), c.end()
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define cpresent_vector(c,x) (find(all(c),x) != (c).end())
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define matrix vector< vector<ll> >
//vector< vector<int> >Matrix(N, vector<int>(M,0));
#define gc getchar_unlocked
#define MAXNN 1000010
#define mod 761238923
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
int dp[1005][1005],arr[1005];

int recur(int i,int j)
{
    if(i>j)
        return 0;
     if(i==j)
        return arr[i];
     if(dp[i][j]!=-1)
        return dp[i][j];

    int val1,val2;
    if(arr[j] > arr[i+1])//i then j
    {
        val1=arr[i]+recur(i+1,j-1);
    }
    else//arr[j]<=arr[i+1]  i then i
    {
        val1=arr[i]+recur(i+2,j);
    }
    if(arr[i] >= arr[j-1])// j then i
    {
        val2=arr[j]+recur(i+1,j-1);
    }
    else//j then j
    {
        val2=arr[j]+recur(i,j-2);
    }

    dp[i][j]=std::max(val2,val1);
    return dp[i][j];

}
int main()

{
    inputfile();
   int n,t=1;
     int i,j,sum;
   scanint(n);
   while(n!=0)
   {
    sum=0;
    REP(i,1,n)
    {scanint(arr[i]);
    sum=sum+arr[i];
    }
    M(dp,-1);
    printf("In game %d, the greedy strategy might lose by as many as %d points.\n",t++,(2*recur(1,n)-sum));
    scanint(n);
   }
    return 0;
}
