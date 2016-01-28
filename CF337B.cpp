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

vector<ll> ind;
ll a[1000010];
int main(int argc, char const *argv[])
{
 BOOST;
 ll n;
 while(cin >> n)
 {
  ind.clear();
  ll min = INT_MAX;
  FOR(i,1,n+1)
  {
    cin >> a[i];
    min = std::min(min,a[i]);
  }
  FOR(i,1,n+1)
  {
    if(a[i] == min)
      ind.push_back(i);
  }

  ind.push_back(ind[0]);

  ll ans  = (ll)(min*n); 
  int l =ind.size();
  if(l > 2)
  {
    for(int i = 0;i < l-2 ;i++)
    {
      ans = max(ans, min*n  + ind[i+1] - ind[i]-1);
    }
    ans = max(ans, min*n + n-ind[l-2] + ind[l-1] -1);
  }
  else
  {
    ans = max(ans, min*n + n-1LL);
  }

  cout << ans << endl;
}
return 0;
}