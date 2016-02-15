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

ll arr[MAXN];
ll dp[MAXN][3];
ll n,a,b;
ll len;
ll maxint = (ll)1e16;
set<ll> pms;
vector<ll> primes;

void preprocess()
{
    primes.emplace_back(2);
    for(int i =3 ;i < 31624; i++)
    {
        bool isPrime = 1;
        for(int j = 0; primes[j]*primes[j]<=i; j++)
        {
            if( i%primes[j] == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if(isPrime)
            primes.emplace_back(i);
    }
    len = primes.size();
}

ll factorise(ll x)
{
    int i = 0;
    while(i < len && x > 1)
    {
        if( x%primes[i] == 0)
        {
            pms.insert(primes[i]);

            while( x%primes[i] == 0)
            {
                x /= primes[i];
            }
        }
        i++;
    }
    if( x != 1)
        pms.insert(x);
}

ll solve(ll p)
{
    if(arr[0]%p == 0)
        dp[0][0] = 0;
    else if( (arr[0]-1)%p == 0 || (arr[0]+1)%p == 0)
        dp[0][0] = b;
    else
        dp[0][0] = maxint;
    /*dp, the minimum cost
     to make the gcd of the first i elements > 1 
    if 2) we have already removed some subarray from the list 
    1) if we are in the process of removing some subarray from the list 
    0)if we haven't removed any subarry from the list yet.
    */
    dp[0][1] = a;
    dp[0][2] = a;
    FOR(i,1,n-1)
    {
        if(arr[i] % p == 0)
            dp[i][0] = dp[i-1][0];
        else if( (arr[i]-1)%p == 0 || (arr[i]+1)%p == 0 )
            dp[i][0] = dp[i-1][0]+b;
        else
            dp[i][0] = maxint;

        dp[i][1] = a + min(dp[i-1][1],dp[i-1][0]);
        //cost uptil now
        dp[i][2] = dp[i][1];

        if(arr[i] % p == 0)
            dp[i][2] = min(dp[i][2] , dp[i-1][2]);
        else if( (arr[i]-1)%p == 0 || (arr[i]+1)%p == 0 )
            dp[i][2] = min(dp[i][2], dp[i-1][2] + b);
    }   
    return min(dp[n-1][0], min(dp[n-1][1] , dp[n-1][2]) );
}
//http://www.codeforces.com/contest/624/problem/D
int main(int argc, char const *argv[])
{
    BOOST;
    preprocess();
    cin >> n >> a >> b;
    FOR(i,0,n-1)
    cin >> arr[i];

    for(ll i = -1; i<=1 ; i++)
    {
        factorise(arr[0] + i);
        factorise(arr[n-1] + i);
    }
        
    ll ans = (n-1)*a  + b;
    repstl(pms)
    {
        ans = min(ans,solve(*it));
    }
    cout << ans << endl;
    return 0;
}