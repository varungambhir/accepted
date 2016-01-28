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

int a[110];
int xorsum[110]={0};

int main(int argc, char const *argv[])
{
  BOOST;
  int n;
  cin>>n;
  cin>>a[1];
  
  xorsum[1] = a[1];
  FOR(i,2,n+1)
  {
    cin>>a[i];
    xorsum[i] = xorsum[i-1] ^ a[i];
  }
  int ans = 0;

  FOR(i,1,n+1)
  {
    int k = 0;
    FOR(j,i,n+1)
    {
        k = k ^ a[j];
        ans = max(ans,k);
    }
    
  }

  cout<<ans<<endl;
  return 0;
}
