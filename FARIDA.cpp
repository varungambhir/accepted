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

//Classic DP on Trees
int main(int argc, char const *argv[])
{
  BOOST;
  int t;
  cin >> t;
  int k = 0;
  while( (++k) <= t )
  {
    int n;
    cin >> n;
    FOR(I,0,n-1) cin >> a[I];
    if(!n)
    {
      cout <<"Case " << k << ": " << 0 << endl;
      continue;
    }
    if(n == 1) {
     cout <<"Case " << k << ": " << a[0] << endl;
      continue;

    } else if (n == 2) {
      cout << "Case " << k << ": " << max(a[0],a[1]) << endl;
      continue;
    }

    dp[0] = a[0];
    dp[1] = max(a[1],a[0]);

    FOR(i,2,n-1) {
      dp[i] = max(dp[i-1], a[i] + dp[i-2]);
    }

    cout << "Case " << k << ": " << dp[n-1] << endl;

  }
  return 0;
}