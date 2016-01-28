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
#define MAXN 22
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
int L[1001][1001];
std::vector<int> alex,temp;
int lcs()
{   int i,j;
    //memset(L,-1,sizeof(L));
    int n=alex.size();
    int m=temp.size();
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
{
    if(i==0 || j==0)
    {
        L[i][j]=0;        
    }
    else if(alex[i-1]==temp[j-1])
    {
        L[i][j]=L[i-1][j-1]+1;
    }
    else
        L[i][j]=max(L[i-1][j],L[i][j-1]);
}
return L[n][m];
}
int main()
{   int t,i,j,k;
    scanint(t);
    while(t--)
    {
        alex.clear();
        while(S(i) && i!=0)
            alex.push_back(i);

        int ans=0;
        while(S(i) && i!=0)
        {
            temp.clear();
            temp.push_back(i);
            while(S(j) && j!=0)
                temp.push_back(j);
            ans=max(ans,lcs());
        }

        printf("%d\n",ans);
    }
    return 0;
}
