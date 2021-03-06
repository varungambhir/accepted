#include <bits/stdc++.h>
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
#define present_mapset(c,x) ((c).fparent(x) != (c).end())
#define cpresent_vector(c,x) (fparent(all(c),x) != (c).end())
#define repstl(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define matrix vector< vector<ll> >
#define PI acos(-1.0)
#define EPS 1e-9
#define F1 first
#define S2 second
#define Lf 2*r
#define Rg 2*r+1
//vector< vector<int> >Matrix(N, vector<int>(M,0));
#define gc getchar_unlocked
#define MAXNN 100010
#define mod 1e9+7

inline void inputfile() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
}
inline void cpp_input()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);}
template <typename T>
void scanint(T &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int parent[MAXNN],arr[MAXNN],rank[MAXNN];
void func(int n)
{
for(int i=0; i<=n; i++)  
{
    parent[i] = i;
    rank[i] = 0;
    arr[i]=-1;
}
return;
}
int find(int x)
{
    if (parent[x]!=x)
    {
        parent[x]=find(parent[x]);
    }
    return parent[x];
}
void Union(int x,int y)
{
    int xroot,yroot;
    xroot=find(x);
    yroot=find(y);
    if(xroot==yroot)
        return;
    if(rank[xroot]<rank[yroot])
        parent[xroot]=parent[yroot];
    else if(rank[xroot]>rank[yroot])
        parent[yroot]=parent[xroot];
    else
    {   
        parent[yroot]=parent[xroot];
        rank[xroot]=rank[xroot]+1;
    }
}
int main()
{
  inputfile();
  int t,i,n,cnt,m,x,y;
  scanint(t);
  while(t--)
  {
    scanint(n);
    func(n);
    scanint(m);
    if(m==0)
       { printf("%d\n",n); continue;}
    FF(i,0,m)
    {
        scanint(x);
        scanint(y);
        Union(x,y);
    }
    cnt=0;
    FF(i,0,n)
    {
        if(parent[i]==i)
            cnt++;
    }
    printf("%d\n",cnt );
  }

  return 0;
}


