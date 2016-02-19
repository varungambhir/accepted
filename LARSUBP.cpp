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

 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/
#define MAXN 3000005
#define MOD 1000000007
int n;
char s[100010];
int a[100010];
int dp[10010][11];
int main(int argc, char const *argv[])
{
    BOOST;
    int t;
    ll ans;
    SD(t);
    FOR(zz,1,t)
    {
        memset(dp,0,sizeof(dp));
        scanf("%s",s);
        n = strlen(s);
        ans = 0;
        FOR(i,1,n)
        {
            a[i] = (int)( s[i-1] -'0');
            dp[i][a[i]]++;
        }

        ans = 1;
        for(int i = n-1;i>=1 ; i--)
        {
            FOR(j,0,9)
            {
               dp[i][j]  += dp[i+1][j];
               dp[i][j] %= MOD;
            }
            FOR(j,a[i]+1,9)
            {
                dp[i][a[i]] += dp[i+1][j];
                dp[i][a[i]]%= MOD;
            }
        }
        ans  = 0;
        FOR(i,0,9)
        {
            //  if(i >= a[1])
            ans += dp[1][i];
            ans %= MOD;
        }
        printf("Case %d: %lld\n",zz,ans);

    }
    return 0;
}