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

int n;
  int a[100000+5];
  int dp[100000+5];
  

int main(int argc, char const *argv[])
{
  //BOOST;
  cin>>n;

  FOR(i,1,n+1)
  cin>>a[i];
  
  dp[1] = 1;
  
  FOR(i,2,n+1)  
  {
    if(a[i] > a[i-1])
      dp[i] = dp[i-1] + 1;
    else
      dp[i] = 1; 
  }
  for(int i = n -1; i>=1 ; --i)
  {
      if(a[i] > a[i+1] && dp[i]<= dp[i+1])
      {
        dp[i] = dp[i+1] + 1;
      }
  }

  int ans = 0;

  FOR(i,1,n+1)
  {
    ans = ans + dp[i];
  //  debug(dp[i]);
  }
  cout<<ans<<endl;

  return 0;
}
