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
#define F second
#define S first
#define L 2*r
#define R 2*r+1
//vector< vector<int> >Matrix(N, vector<int>(M,0));
#define gc getchar_unlocked
#define MAXNN 10002
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
const int INF = 0x3f3f3f3f;

vector< pii > G[MAXNN];
int d[MAXNN];

void dijkstra(int start)
{
  int u,v,i,c,w;
  //comparator queue defined in greater<T>
  priority_queue< pii , vector< pii > , greater< pii > > Q;

  //distnace infinite
  M(d,0x3f);

  Q.push(make_pair(0,start));//shortest path weight, starting node
  //or Q.push(pii(0,start));
  d[start] = 0;

  while(!Q.empty())
  {
    u = Q.top().second;
    c = Q.top().first;
    Q.pop();
    /*
    We have discarded the visit array as we do not need it.
        If d[u] has already a better value than the currently
        popped node from queue, discard the operation on this node.
        */
        if(d[u] < c) continue;

        /*
        In case you have a target node, check if u == target node.
        If yes you can early return d[u] at this point.
        */

        /*
        Traverse the adjacent nodes of u. Remember, for the graph,,
        the pair is assumed to be (node, weight). Can be done as
        you like of course. */

  FF(i,0,G[u].size())
  {
    v = G[u][i].first;//node;
    w = G[u][i].second;//weight

  if(d[v] > d[u] + w)
  {
    d[v] = d[u] + w;
    Q.push(make_pair(d[v],v));
  }

  }

}
return;
}


int main()
{
  inputfile();
  //cpp_input();
  int t,i,v,e,temp,target,n,m,u,w,start;
  cin>>t;
  while(t--)
  {
    cin>>n>>e;//n node e edge
    //graph reset
    REP(i,1,n)
    G[i].clear();
    // read all edges . u to v with cost w
    REP(i,1,e)
    {
      cin>>u>>v>>w;
      G[u].push_back(make_pair(v,w));
      //G[v]/push_back(make_pair(u,w));//only if bi-directional
      //not in case of single source directed path
    }

    //start and source vertex
    cin>>start>>target;

    dijkstra(start);

    if(d[target]>=INF)
      printf("NO\n");
    else
      printf("%d\n",d[target]);

  }
    return 0;
}
