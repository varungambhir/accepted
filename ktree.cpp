#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long  long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define FOR(i,a,n) for(int (i)=(a);(i) < (n); ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define FF(i,a,n) for ((i) = (a); (i)<(n);++(i))
#define REP(i,a,n) for ((i) = (a); (i)<=(n);++(i))
#define V(x) vector<x>
#define Sd(x) scanf("%d",&x)
#define all(c) c.begin(),c.end()
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define F first
#define S second
#define PI acos(-1.0)
#define EPS 1e-9
#define Lf 2*r
#define Rg 2*r+1
#define M(x,i) memset(x,i,sizeof(x))
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define matrix vector< vector<ll> >

inline void inputfile()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	#endif
}
inline void cpp_input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
#define MAX 100010
#define mod 1000000007

long long dp[105][2];

ll n,k,d;

ll rec(ll total , bool flag)
{

if(dp[total][flag]!=-1)
  return dp[total][flag];

  if(total > n)
    return 0;
  
  if(total==n)
  {
    if(flag==true)
      return 1;
    else
      return 0;
  }

ll c =0;
for(int i=1 ; i<=k ;i++)//mistake was i = 0 resulted in infinte calls
{
  if(total + i <= n)
  {
    if(flag==false)
    {
      if(i>=d)
        c = c + rec(total + i, true);
      else
        c = c + rec(total + i, false);
    }
    else//flag==true
    {
      c = c + rec(total + i, true);
    }

  }
  else
    break;
}
dp[total][flag] = c%mod;
return dp[total][flag];
}
int main()
{
	inputfile();
  cpp_input();

  cin>>n>>k>>d;

FOR(i,0,105)
{
  dp[i][0]=dp[i][1]=-1;
}
 ll ans= rec(0,0);

  cout<<dp[0][0]<<"\n";
  

   return 0;
}
