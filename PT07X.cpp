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
#define repstl(v) for(typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
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

/* Agar Nhi Koshish Karoge toh pakka successful nhi hoge */

int dp[100010][2];
std::vector<int> graph[100010];
bool visited[100010] = {0};
int n;

int rec(int ind,int parent,int mark = 0)
{
  if(dp[ind][mark] != -1)
    return dp[ind][mark];

  int &ans = dp[ind][mark];
  ans = 0;
  repstl(graph[ind])
  {
    if(*it == parent)
      continue;
    if(mark)
    {
      ans += min( rec(*it,ind,0) , rec(*it,ind,1));
    }
    else
    {
      ans += rec(*it,ind,1);
    }

  }

  if(mark)
    ans += 1;
  return ans;
}

int main(int argc, char const *argv[])
{
  BOOST;
  cin >> n;
  memset(dp,-1,sizeof(dp));
  FOR(i,0,n-1)
  {
    int x,y;
    cin >> x >> y;
    graph[x].pb(y);
    graph[y].pb(x);
  }

  int ans = 1 ;
  if(n!=1)
    ans = min(rec(1,-1,0) , rec(1,-1,1));
  cout << ans <<endl;

  return 0;
}