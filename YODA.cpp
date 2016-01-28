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

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define dforn(i,n) for(int i=(int)n-1;i>=0;i--)
#define all(v) v.begin(),v.end()

long long cant[26];
long long dp[26];

long long comb(long long a, long long b)
{
    b = min(b,a-b);
    vector<int> vec(100,0);
    for(int i=2;i<=b;i++)
    {
        int j =i;
        for(int t=2;t<100;t++)
        {
            while(j%t==0)
            {
                j/=t;
                vec[t]++;
            }
        }
    }
    long long res = 1;
    for(int i=a-b+1;i<=a;i++)
    {
        int j = i;
        for(int t=2;t<100;t++)
        {
            while(j%t==0 && vec[t]>0)
            {
                vec[t]--;
                j/=t;
            }
        }
        res *= j;
    }
    return res;
}

long long calc()
{
    dp[25] = 1;
    for(int i=24;i>=0;i--)
    {
        dp[i] = dp[i+1]*comb(cant[i]+cant[i+1],cant[i]);
        cant[i] += cant[i+1];
    }
    return dp[0];
}

int main()
{

    string st;
    while(getline(cin,st))
    {
        forn(i,26)
            cant[i] = 0;
        forn(i,st.size())
        if(st[i]>='A'&&st[i]<='Z')
            cant[st[i]-'A']++;
        else if(st[i]>='a'&&st[i]<='z')
            cant[st[i]-'a']++;
        int tot = 0;
        forn(i,26)
            tot += cant[i];
        int res = 0;
        if(tot%2==0)
        {
            forn(i,26)
            if(cant[i]%2==1)
                res = -1;
            else
                cant[i]/=2;
        }
        else{
            int t = 0;
            forn(i,26)
            if(cant[i]%2==1)
                t++;
            if(t!=1)
                res = -1;
            forn(i,26)
                cant[i] /= 2;
        }
        if(res==-1)
            cout << 0 << endl;
        else
            cout << calc() << endl;
    }
}
