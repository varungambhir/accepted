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
#define V(x) vector<x>
#define Sd(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define all(c) c.begin(), c.end()
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define cpresent_vector(c,x) (find(all(c),x) != (c).end())
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define matrix vector< vector<ll> >
#define F1 first
#define S2 second
#define Lf 2*r
#define Rg 2*r+1
//vector< vector<int> >Matrix(N, vector<int>(M,0));
#define gc getchar_unlocked
#define MAXNN 1000001
#define mod 1000000007
inline void inputfile() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
}
inline void cpp_input()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);}
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

char a[1000010];
ll ar[26]={0};
std::vector<ll>v[26];
int main()
{
    inputfile();
    //cpp_input();
    scanf("%s",a);
    for (ll i = 0; a[i]!='\0'; ++i)
    {
        v[(ll)(a[i] - 'a')].pb(i);
        ar[(ll)(a[i] - 'a')]=1;
    }
    for(ll i=0;i<26;i++)
    {
        if(ar[i])
        sort(v[i].begin(),v[i].end());
    }

    ll q;
    scanintll(q);
    while(q--)
    {
        ll l,r;
        char inp;
        scanf("%c",&inp);
        scanintll(l);scanintll(r);
        l--,r--;
        ll cnt;
        ll id = (ll)(inp - 'a');
        std::vector<ll>::iterator low,up,it;
        it=v[id].begin();
        low=std::lower_bound(v[id].begin(),v[id].end(),l);
        up =std::upper_bound(v[id].begin(),v[id].end(),r);
       //cout<<"Up : "<<(up-v[id].begin())<<"  low : "<<(low-v[id].begin())<<"\n";
        cnt = up-v[id].begin() - (low-v[id].begin());

        printf("%lld\n",cnt);
    }

    return 0;
}

