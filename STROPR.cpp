#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define eb emplace_back
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
#define MAXN 1000010
#define MOD 1000000007LL

ll a[100010];
ll inv[MAXN];
ll modpow(ll a,ll p ,ll mod=MOD)
{//a^p %mod
    ll ret = 1;
    while(p)
    {
        if(p & 1)
            ret = (ret*a)%mod;
        a = (a*a)%mod;
        p /= 2;
    }
    return ret%mod;
}

ll inver(ll a)
{
    return modpow(a,MOD - 2LL);
}

int main(int argc, char const *argv[])
{
    BOOST;
    int t;
    cin >> t;

    FOR(i,1,MAXN)
    inv[i] = inver(i);

    while(t--)
    {
        ll m,n,x;
        cin >> n >> x >> m;
        FOR(i,1,n)
        {
            cin >> a[i];
            a[i] = a[i] % MOD;
        }

        ll ans = a[x];
        ll num = m%MOD;
        ll den = 1;
        ll val = 1;
        ROF(i,x-1,1)
        {
            val = (((val*num)%MOD)*inv[den])%MOD;
            
            ans = (ans + (a[i]*val))%MOD;
            den++;
            num = (num + 1)%MOD;
        }
        cout << ans << endl;
    }

    return 0;
}