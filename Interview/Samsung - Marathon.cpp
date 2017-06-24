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
#define foreach(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define is_present_mapset(c,x) ((c).find(x) != (c).end())
#define is_present_vector(c,x) (find(c.begin(),c.end(),x) != (c).end())
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

vector<int> G[140005];
int cycle[140005]={0}; //0 not processed , 1 cycle // 2 under process // 3 processed and returned no cycle
bool visited[140005] = {0};

int cnt;

int dfs(int node) {

  if(visited[node]) {
    if(cycle[node] == 1) //0 not possible.  
      return 1;
    else if(cycle[node] == 2) { // was under processing: i.e loop
      cycle[node] = 1;
      return 1;
    } else  // cycle[node] == 3
      return 3; // processed but no loop
  }

  visited[node] = true;
  bool one_cycle = false;
  cycle[node] = 2; //default under process
  
  for(int &i: G[node]) {
    int nvalue = 0;
    if(cycle[i] == 1) {
      nvalue = 1;

    } else if(cycle[i] == 3) {
      nvalue = 3;

    } else { // not visited or under process then most likely a loop
      nvalue = dfs(i);
    }

    if(nvalue == 1) {
      one_cycle = true;
      cnt++;
    }// else if(nvalue == 3) { // 2 impossible
     // ;}
  }

  if(one_cycle)
    cycle[node] = 1;

  // if node still not 1 then no cycle i.e. 3
  if(cycle[node] != 1)
    cycle[node] = 3;

  return cycle[node];
}

//https://www.hackerrank.com/contests/code-the-next/challenges/the-marathon
int main(int argc, char const *argv[])
{
  BOOST;
  int t;
  cin >> t;
  int n,m,a,b;
  while(t--) {
    cin >> n >> m;
    FOR(i,1,m) {
      cin >> a >> b;
      G[a].push_back(b);
    }
    cnt = 0;
    FOR(i,1,n) {
      dfs(i);
    }

    cout << cnt << endl;

    cnt = 0;
    FOR(i,0,n+1) {
      G[i].clear();
      cycle[i] = 0;
      visited[i] = 0;
    }
  }
  return 0;
}