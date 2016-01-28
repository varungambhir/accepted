#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define F first
#define S second
#define L 2*node
#define R 2*node+1
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define MAX 1010
#define MOD 1000000007

ll dp[MAX][MAX];

int main(int argc, char const *argv[])
{
    BOOST;
    ll n,k,x;
    cin>>k;
    memset(dp,0,sizeof(dp));
    //npr/r! = ncr
    ll ans = 1;
    n  = 0;
    FOR(i,1,1000+1)
    {     //n  r
        dp[i][i] = dp[i][0] = 1;
        FOR(j,1,i)
        {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
        }
    }

    cin>>n;

    FOR(i,1,k)
    {
        cin>>x;

        ans = (ans* dp[n+x-1][x-1])%MOD;

        n += x;
    }

    cout<<ans<<endl;

    return 0;
}
