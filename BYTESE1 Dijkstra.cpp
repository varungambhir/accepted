#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define FOR(i,a,n) for(int i=(a);i<(n);++i)
#define FF(i,a,n) for(i=(a);i<(n);++i)
#define REP(i,a,n) for(i=(a);i<=(n);++i)
#define V(x) vector<x>
#define Sd(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define all(c) c.begin(), c.end()
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define repstl(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define matrix vector< vector<ll> >
#define PI acos(-1.0)
#define EPS 1e-9
#define F first
#define S second
#define Lf 2*r
#define Rg 2*r+1
//vector< vector<int> >Matrix(N, vector<int>(M,0));
#define gc getchar_unlocked
#define MAXNN 101
#define mod 1000000007

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

#define pofp pair< pair< int,int > , pair< int,int > >
#define INF (1<<25)
int R,C;

pofp G[MAXNN][MAXNN];

bool inrange(int r,int c)
{
  if((r>=0 && r<R) && (c>=0 && c<C))
  {
    return true;
  }
  else
  return false;
}

struct comp{
bool operator()(const pofp &a, const pofp &b)
{
  return (a.first.first > b.first.first);
}

} ;

void assigndata(pofp G,int &b,int &w,int &u,int &v)
{
  b = G.first.first; u=G.second.first; v = G.second.second; w =G.first.second;
}
void dijsktra()
{
  priority_queue< pofp , vector< pofp > , comp > Q;
  int u,v,w,b,b1,u1,w1,v1,i,j;
  G[0][0].first.first = G[0][0].first.second;//i.e. = v = min distance yet
  Q.push(G[0][0]);
  while(!Q.empty())
  {
    assigndata(Q.top(),b,w,u,v);
    Q.pop();
    REP(i,-1,1)
    {
      REP(j,-1,1)
      {
        if((i!=j) && (i+j) && inrange(u+i,v+j) )
        {
            assigndata(G[u+i][v+j],b1,w1,u1,v1);
            if( w1 + b < b1)//b1 total dis for neigbour,b parent + w2 weight
              {
                G[u+i][v+j].first.first = w1 + b;
                Q.push(G[u+i][v+j]);
              }
        }
      }
    }
  }
  return;
}

int main()
{
  inputfile();
  cpp_input();
  int t,u,v,j,tme,w,i,m;
  cin>>t;
  while(t--)
  {
    cin>>R>>C;
    FF(i,0,R)
    {
      FF(j,0,C)
      {
        cin>>m;
        G[i][j].first.first = INF;
        G[i][j].first.second = m;
        G[i][j].second.first = i;
        G[i][j].second.second = j;
      }
    }
  cin>>u>>v>>tme;
  u--;v--;
  dijsktra();
  if(G[u][v].first.first <= tme)
    cout<< "YES\n" << tme-G[u][v].first.first <<"\n";
  else
    cout<<"NO\n";

  }

    return 0;
}
