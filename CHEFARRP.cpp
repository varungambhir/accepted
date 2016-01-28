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
ll v[60];
ll sum[60];
ll product[60];
int main(int argc, char const *argv[])
{
  BOOST;
  int t,n;
  cin>>t;
  while(t--)
  {
    cin >> n;
    sum[0] = 0;
    product[0] = 1;
    FOR(i,1,n+1)
    {
      ll x;cin >> x;
      v[i] = x;
      sum[i] = x + sum[i-1];
      product[i] = x*product[i-1];
    }
    int ans= n;
    FOR(i,1,n+1)
    {
      FOR(j,i+1,n+1)
      {
        if((sum[j] - sum[i-1]) == ( product[j] / product[i-1] ))
        ans++; 
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}