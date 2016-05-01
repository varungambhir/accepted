#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
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
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif

#define MOD 1000000007

ll arr[(int)1e5+10];
ll dp[(int)1e5+10][2];
ll sum[(int)1e5+10];

ll rec(ll i, ll j = 0)
{
    if(dp[i][j] != -1)
        return dp[i][j];

    if(!j)//max
    {
        if(i>3)
        {
            ll val;

            val = max(arr[i] + rec(i-1,j^1),
                      max(arr[i]+arr[i-1]+rec(i-2,j^1),
                          arr[i] + arr[i-1] + arr[i-2]+rec(i-3,j^1))
                      );
            dp[i][j] = val;
        }
        else if(i == 3)
            dp[i][j] = arr[3] + arr[2] + arr[1];

        else if(i == 2)
            dp[i][j] = arr[2] + arr[1];

        else if (i == 1)
            dp[i][j] = arr[1];
        else
            dp[i][j] = 0;
    }
    else//min
    {
        if(i<=3)
            dp[i][j] = 0;
        else//i >3
        {
            ll val;

            val = min(rec(i-1,j^1),
                      min(rec(i-2,j^1),
                          rec(i-3,j^1))
                      );
            dp[i][j] = val;
        }
    }
    //trace3(i,j,dp[i][j]);
    return dp[i][j];
}

//https://www.hackerrank.com/challenges/play-game
int main(int argc, char const *argv[])
{
    BOOST;
    int t;
    int n;
    cin >> t;
    while(t--)
    {

        cin >> n;
        memset(dp,-1,sizeof(dp));
        //memset(sum,0,sizeof(sum));
        ROF(i,n,1)
        cin >> arr[i];

        sum[0] = 0;

        FOR(i,1,n)
        sum[i] = arr[i] + sum[i-1];

        ll ans = rec(n,0);//0 me 1 him
        cout << ans << endl;

    }
    return 0;
}
