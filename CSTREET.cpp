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
//#define pii pair<int,int>
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
#define MAXNN 1000005
#define mod 1000000007
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
//(w,(u,v)) format
int parent[MAXNN],rank[MAXNN],total_cost,N,E;
vector< pair<int,pair<int,int> > > GRAPH,MST;

inline void func()
{
    F(i,0,MAXNN)
    {
        parent[i]=i;
        rank[i]=0;
    }
    GRAPH.clear();
    MST.clear();
}
int find(int x)
{
    if(parent[x]!=x)
        parent[x]=find(parent[x]);

    return parent[x];
}
void Union(int x,int y)
{
    int xroot,yroot;

    xroot=find(x);
    yroot=find(y);

    if(xroot==yroot)
        return;
    if(rank[xroot] < rank[yroot])
        parent[xroot]=parent[yroot];

    else if(rank[xroot] > rank[yroot])
        parent[yroot]=parent[xroot];

    else
    {
        parent[yroot]=parent[xroot];
        rank[xroot]=rank[xroot]+1;
    }
}
void Kruskal_genrateMST()
{
    int i,pu,pv;
    std::sort(GRAPH.begin(),GRAPH.end());//increasing weight
    total_cost=0;
    FF(i,0,E)
    {
        pu=find(GRAPH[i].second.first);
        pv=find(GRAPH[i].second.second);
        if(pu!=pv)//No cycle formed
        {
            MST.push_back(GRAPH[i]);
            total_cost+=GRAPH[i].first;
            Union(pu,pv);
        }
    }
}
void printMST()
{
    int i ,sz;
    sz=MST.size();
    FF(i,0,sz)
    {
        printf("%d ",MST[i].second.first);
        printf(", %d ",MST[i].second.second );
        printf(", %d\n",MST[i].first);
    }
    printf("%d\n", total_cost);//minimum cost
}

int main()
{   //inputfile();
    int n,m,t,p;
    scanint(t);
    while(t--){
        func();
    scanint(p);
    scanint(n);scanint(m);
    E=m;
    int t1,t2,t3;
    F(i,0,m)
    {
        scanint(t1);scanint(t2);scanint(t3);
        GRAPH.push_back(make_pair(t3,make_pair(t1,t2)));
    }
    Kruskal_genrateMST();
    printf("%d\n",total_cost*p);
             }
    return 0;
}



