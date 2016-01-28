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
std::vector<ll> v[MAXN];
ll cost[MAXN] = {0};
ll parent[MAXN] = {0};
ll inds[MAXN] = {0};
ll ind = 1;
ll sum=0 , ans = 1;
stack<ll> s;
std::vector<ll> temp;

void DFSTarjan(ll x)
{
  parent[x] = inds[x] = ind;
  ind++;
  cycle[x] = 1;//on stack
  s.push(x);

  repstl(v[x])
  {
    if(inds[*it] == 0)
    {
      DFSTarjan(*it)  ;
      parent[x]  = min(parent[x],parent[*it]);
    }
    else if(cycle[*it])
    {
      parent[x] = min(parent[x],inds[*it]);
    }
  }

  if(parent[x] == inds[x])
  {
    ll val = LONG_MAX;
    ll cnt = 0;
    temp.clear();
    //s.pop();
    do
    {
      temp.push_back(s.top());
      cycle[s.top()] = 0;
      val = min(val,cost[s.top()]);
      s.pop();
    }while(temp.back()!=x);

    sum += val;
    repstl(temp)
    {
      if(cost[*it] == val)
        cnt++;
    }
    ans = (ans*cnt)%MOD;

  }

  return;
}


int main(int argc, char const *argv[])
{
  BOOST;
  //INPFILE;
  ll n,m,u,v2;
  cin>>n;
  FOR(i,1,n+1)
  {
    cin>>cost[i];
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
    if(!inds[i])
    {
      DFSTarjan(i);
    }
  }

  cout<< sum << " " << ans << "\n";
  return 0;
}
