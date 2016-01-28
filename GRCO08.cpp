#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
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
#define MAXN 2020
#define MOD 1000000007
 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/
ll val = 0;
bool explore[1005][1005] = {0};
bool cycle[1005][1005] = {0};
ll a[1005][1005] = {0};
ll cnt[1000005] = {0};
ll n,m,maxi,fans;
bool flag;
bool check(ll x,ll y,ll sx , ll sy)
{
  if(x == sx && y == sy) return 0;
  return 1;  
}
ll dx[4]= {-1LL,1LL,0LL,0LL};
ll dy[4]= {0LL,0LL,-1LL,1LL};
ll dfs(ll x,ll y, ll sx , ll sy, ll p)
{
  if(flag) return 0;
  if(cycle[x][y])
  {
    val = max(val,cnt[p]);
    flag = 1;
    return 0;
  }

  explore[x][y] = 1;
  cycle[x][y] = 1;

  vector<ll> v;
  FOR(i,0,3)
    if( check(x+dx[i],y+dy[i],sx,sy) && a[x+dx[i]][y+dy[i]] == p )
      v.push_back( 1 + dfs(x+dx[i],y+dy[i],x,y,p)  );
  sort(v.rbegin(),v.rend());

  if(!v.empty())
    val = max(val,v[0]);
  if(v.size()>=2)
    val = max(val,v[0]+v[1] -1);

  cycle[x][y] = 0;

  if(!v.empty())
    return v[0];
  else 
    return 1;  
}

int main(int argc, char const *argv[])
{
  BOOST;
  cin >> n >> m;
  FOR(i,1,n)
  FOR(j,1,m)
  {
    cin >> a[i][j];
    cnt[ a[i][j] ]++;
  }
  fans = -1;
  
  FOR(i,1,n)
  {
    FOR(j,1,m)
    {
      val = 0;    
      flag = 0;
      maxi = 0;
      if(!explore[i][j])
      {
        maxi = dfs(i,j,-1,-1,a[i][j]);
        maxi =  max(maxi,val);
        fans = max(maxi,fans);
      }
    }
  }

  cout << fans << endl;
  return 0;
}