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
#define MAXNN 120000
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
struct aa
{
    char ss[105];
}saved[105];
char st[105];
int p[110],m[110],ind;

void lis(char *x,int n)
{   priority_queue<int> qi[105];
    ind=0;
    M(p,MAXNN);
    int lo,hi,l=0;
    F(i,0,n)
    {
        lo=1;
        hi=l;
        cout<<"-----------------------------------------------------------\n\n";
        cout<<"::: i : "<<i<<" x[i] : "<<x[i]<<endl<<endl;
        while(lo<=hi)
        {
            int mid;
            mid=ceil((lo+hi)/2);
            cout<<"mid : "<<mid;
            cout<<" value : "<<x[m[mid]]<<endl<<endl;

            if(x[m[mid]]<=x[i])
                {lo=mid+1;
                cout<<"x[m[mid]] : "<<x[m[mid]]<<endl<<endl;
                cout<<"low = mid+1 : low : "<<lo<<" high : "<<hi<<endl<<endl;
          }
            else
                {hi=mid-1;
                cout<<"high = mid-1 : low:"<<lo<<" high : "<<hi<<endl<<endl;
                }
        }

        int newL=lo;
        cout<<"newl : "<<newL<<endl<<endl;
        p[i]=m[newL-1];
        m[newL]=i;
        qi[newL].push(i);

        cout<<"newl : "<<newL<<" m[newl]=i is : "<<m[newL]<<endl<<endl;
        if(newL>l)
            l=newL;
        cout<<"newl : "<<newL<<endl;
        cout<<"l : "<<l<<endl<<endl;
    }
   while(!qi[l].empty())
   {
        int k=qi[l].top();
        for(int i=l-1;i>=0 ;i--)
        {
            saved[ind].ss[i]=x[k];
            k=p[k];
        }
        ind++;
        qi[l].pop();
   }
   F(i,0,ind)
   {
        F(j,0,l)
        printf("%c",saved[i].ss[j]);
        printf("\n");

   }
    /*int k=m[l];
    for(int i=l-1;i>=0;i--)
    {
        s[i]=(int)x[k];
        k=p[k];
    }
    for(int i=0;i<l;i++)
    {
        printf("%c",s[i]);
    }*/

}
int main()
{
    inputfile();
    int t;
    scanint(t);
    while(t--)
    {
    scanf("%s",st);
    lis(st,strlen(st));
    }

    return 0;
}
