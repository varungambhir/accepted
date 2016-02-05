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

#define MAXN 3010
#define MOD 1000000007
ll dp[MAXN][MAXN];
int v[MAXN];
int used[MAXN] = {0};
ll fact[MAXN];

bool check(ll n,ll k)
{
    if(n < 0 || k <  0)
        return false;   
    return true;
}

ll rec(ll n,ll k)
{
    if(!check(n,k))
        return 0;
    
    if(dp[n][k] != -1)
        return dp[n][k];

    if(!k)
    {
        dp[n][k] = fact[n];
    }
    else if(k == 1)
    {
        dp[n][k] = fact[n] * n;
    }
    else
    {
        dp[n][k] = (n*rec(n,k-1) + (k-1)*rec(n+1,k-2))%MOD;
    }
    return dp[n][k];
}

//http://www.codeforces.com/contest/340/problem/E
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp,-1,sizeof(dp));
    fact[0] = fact[1] = 1;

    int n;
    cin >> n;
    FOR(i,2,n+2)
    fact[i] = (fact[i-1]*i)%MOD;

    FOR(i,1,n)
    {
        cin>>v[i];
    }
    FOR(i,1,n)
    if(v[i] != -1)
        used[v[i]] = 1;
    int K,N;
    K = N = 0;
    FOR(i,1,n)
    {
        if(v[i] == -1)
        {
            if(used[i])
                N++;
            else
                K++;
        }
    }

    //total N+ K
    dp[0][0] = 0;
    ll ans = rec(N,K);

    cout << ans << endl;
    return 0;
}