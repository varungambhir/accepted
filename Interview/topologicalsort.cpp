#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define SL(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L 2*node
#define R 2*node+1
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
#define MAXN 100010
#define MOD 1000000007
 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/

vector<int> G[6];
bool visited[6] = {0};

void toposortUtil(int v, stack<int> &S)
{
  visited[v] = true;
  for(auto &it : G[v])
  {
    if(!visited[it])
      toposortUtil(it, S);
  }

  S.push(v);

}

void topological_sort(int n)
{
  stack<int> S;
  memset(visited,0,sizeof(6));

  FOR(i,0,6)
  if(visited[i] == false)
    toposortUtil(i,S);

  while(S.empty() == false)
  {
    cout << S.top() << " ";
    S.pop();
  }

}

int main(int argc, char const *argv[])
{
  int t;
  G[5].pb(2);
  G[5].pb(0);
  G[4].pb(1);
  G[4].pb(0);
  G[2].pb(3);
  G[3].pb(1);

  topological_sort(6);
  return 0;
}