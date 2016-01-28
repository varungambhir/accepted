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
#define MAX 5000000
#define mod 1000000007

int sieve[MAX+2]={0};
int dp[MAX+2]={0};

void cal()
{
  int i,j;

  for(i=2;i*i<=MAX;i++)
    for(j=i;i*j<=MAX;j++)
      if(sieve[i*j])
        continue;
      else
        sieve[i*j] = i;

dp[0]=dp[1]=0;

for(i=2;i<=MAX;i++)
{
  if(sieve[i]==0)
    dp[i]=1;
  else
    dp[i] = dp[i/sieve[i]] + 1;


}

FF(i,0,MAX)
dp[i+1] = dp[i+1] + dp[i];

}

int main()
{
  inputfile();
  cpp_input();
  cal();
  int t,n,l, a, b,i;
  cin>>t;
  while(t--)
  {
    cin>>a>>b;

    cout<<dp[a] - dp[b]<<"\n";
  }
  return 0;
}
