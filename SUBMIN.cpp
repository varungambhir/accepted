/*
Written by : Ashish Sareen
*/
#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L 2*index
#define R 2*index+1
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

And you run and you run to catch up with the Sun but it's sinking
Racing around to come up behind you again
The Sun is the same in a relative way, but you're older
Shorter of breath and one day closer to death

Every year is getting shorter, never seem to find the time
Plans that either come to naught or half a page of scribbled lines
- Time, Pink Floyd*/

#define MAXN 100010
#define MOD 1000000007

ll modpow(ll a ,ll b ,ll mod=MOD)
{
    ll ret = 1;
    while(b > 0)
    {
        if( b & 1)
            ret = (ret * a);// % mod;
        a = (a*a);//%mod;
        b >>= 1;
    }
    return ret;//%mod;
}

ll nCr(ll n , ll r)
{
    if(r > n/2)
        r = n-r;
    
    ll product = 1;

    for(ll i = 1; i<=r; i++)
    {
        product *= (n - r + i);
        product /= (i);
    }

    return product;

}
ll dp[100][100]={0};
ll a[100];
int main(int argc, char const *argv[])
{
    BOOST;
    ll n;
    cin >> n;
    FOR(i,1,n)
    cin >> a[i];

    FOR(i,1,n)
    {
        dp[i][i] = a[i];
        FOR(j,i+1,n)
        {
            dp[i][j] = min(a[j],dp[i][j-1]);
        }
    }

    ll q;
    cin >> q;
    while(q--)
    {
        ll k,ans;
        cin >> k;
        ans = 0;
        FOR(i,1,n)
        {
            FOR(j,1,n)
            {
                if(dp[i][j] == k)
                    ans++;
            }
        }

        cout << ans <<endl;
    }
    return 0;
}