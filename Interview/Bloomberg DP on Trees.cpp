#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
  template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
  template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
  #define trace(...)
#endif

ll MOD = 1000000007LL;

ll a[10010];
ll dp[10010];

vector<int> adj[1010];
int dp1[1010];
int dp2[1010];
int C[1010];
// With  V
// dp1(V) = Cv + E(dp2[vi]) for (i in range(1,n])
// Without V
// dp2(V) = E(max(dp1[vi],dp2[vi])) for vi belonging to children of V
void dfs(int V, int pV) {
  int sum1 = 0;
  int sum2 = 0;

  for(auto v: adj[V]) {
    if (v == pV) continue;
    dfs(v,V);
    
    sum1 += dp2[v];
    sum2 += max(dp1[v],dp2[v]);
  }

  dp1[V] = C[V] + sum1;
  dp2[V] = sum2;
}

int main(int argc, char const *argv[])
{
  BOOST;
  int n;
  cin >> n;
  FOR(i,1,n) {
    int u,v,c;
    cin >> u >> v >> c;
    adj[u].pb(v);
    adj[v].pb(u);
    C[u] = c;
  }

  dfs(1,0);
  int ans = max(dp1[1],dp2[1]);
  cout << ans << endl;
  return 0;
}