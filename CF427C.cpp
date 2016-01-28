#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L 2*node
#define R 2*node+1
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define MAXN 100005
#define MOD 1000000007

bool cycle[MAXN] = {0};
bool visited[MAXN] = {0};
std::vector<ll> v[MAXN];
ll cost[MAXN] = {0};
ll parent[MAXN] = {0};
ll rank[MAXN] = {0};
std::vector<ll> s;
ll grp[MAXN] = {0};
ll multiplier[MAXN] = {0};

ll find(ll x)
{
  if(parent[x]!=x)
    parent[x] = find(parent[x]);

  return parent[x];
}

void join(ll x,ll y)
{
  ll xroot , yroot;
  xroot = find(x);
  yroot = find(y);
  if(rank[xroot] < rank[yroot])
    parent[xroot] = parent[yroot];
  else if(rank[xroot] > rank[yroot])
    parent[yroot] = parent[xroot];
  else
  {
    parent[yroot] = parent[xroot];
    rank[xroot]++;
  }
}

void DFS(ll x)//finding SCC
{
  cycle[x] = 1;

  repstl(v[x])
  {
    if(cycle[*it])
    {
      while(!s.empty())
      {
        if(s.back()==*it)
          break;

        join(*it, s.back());
        s.pop_back();
      }
    }
    else
    {
      s.push_back(*it);
      DFS(*it);
    }
  }

  cycle[x] = 0;
  visited[x] = 1;
}


int main(int argc, char const *argv[])
{
  BOOST;
  ll n,m,u,v2;
  cin>>n;
  FOR(i,1,n+1)
  {
    cin>>cost[i];
    rank[i] = 0;
    parent[i] =  i;
    grp[i] = LLONG_MAX;
  }
  cin>>m;
  while(m--)
  {
    cin >> u >> v2;
    //debug(u);
    v[u].push_back(v2);
  }

  FOR(i,1,n+1)
  {
    if(!visited[i])
    {
      memset(cycle,0,sizeof cycle);
      s.clear();
      DFS(i);
    }
  }

  FOR(i,1,n+1)
  {
    grp[ find(i) ] = std::min(grp[ find(i) ] , cost[i]);
  }
  //min value is  minimum value of one of the nodes of SCC

  ll ways = 1;
  ll sum = 0;
  

  FOR(i,1,n+1)
  {
    if(cost[i] == grp[ find(i) ])
    {
      multiplier[find(i)]++;
    }

    if( grp[i] != LLONG_MAX )
      sum = sum + grp[i];
  }

  FOR(i,1,n+1)
  {
    if( grp[i] != LLONG_MAX)
    {
      ways = (ways*multiplier[i])%MOD;
    }
  }

    cout<<sum<<" "<<ways<<endl;
  
  return 0;
}