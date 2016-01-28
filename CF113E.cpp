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

ll modpow(ll a, ll b)
{
  ll result = 1;

  while(b>0)
  {
    if(b&1)
    {
      result = (result *a)%MOD;
    }
    a = (a*a)%MOD;
    b = b/2;
  }

  return result%MOD;
}


//ll dp[5][(int)1e7+10];
int main(int argc, char const *argv[])
{
  int n;
  while(cin >> n)
  {
    ll nD,pD,pABC,nABC;
    pD = nD = 0;
    pABC = nABC = 3;
    FOR(i,1,n)
    {
      nD = pABC%MOD;
      nABC = (pABC*2LL + pD*3LL)%MOD;
      pD = nD;
      pABC = nABC;
    }
    cout << nD << endl;
  }  
  return 0;
}