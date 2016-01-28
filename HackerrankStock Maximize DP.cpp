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

ll n;
ll a[100000+5];
int dp[100000+5];

//Stock Maximize HAckerrnk


int main(int argc, char const *argv[])
{
  //BOOST;
  ll t;
  cin>>t;
  while(t--)
  {
    cin>>n;
    FOR(i,1,n+1)
    {
      cin>>a[i];
    }
    if(n==1)
    {
      cout<<0<<endl;
      continue;
    }
    ll max_future_price = 0;
    ll profit = 0;

    ROF(i,n,1)
    {
      max_future_price = std::max(max_future_price, a[i]);

      profit = profit + abs(max_future_price - a[i]);
    }
    cout<<profit<<endl;
  }
  return 0;
}
