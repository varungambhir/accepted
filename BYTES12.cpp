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
//#define L 2*index
//#define R 2*index+1
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
And you run and you run to catch up with the Sun but it's sinking
Racing around to come up behind you again
The Sun is the same in a relative way, but you're older
Shorter of breath and one day closer to death
Every year is getting shorter, never seem to find the time
Plans that either come to naught or half a page of scribbled lines
- Time, Pink Floyd*/
 
#define MAXN 10000010
#define MOD 1000000007
 
 
ll prime[MAXN+1] = {0};
 
inline void sieve()
{
    ll i, j;
 
    for(i=4;i<MAXN;i+=2)
    {
        prime[i] = 2;
    }
 
    for(i = 3; i*i < MAXN; i+=2)
    {
        if(prime[i] != 0)
            continue;
        prime[i] = i;
        for(j = i*2; j<MAXN ; j+=i)
        {
            if(!prime[j])
            prime[j] = i;
        }
    }
}
 
 
ll dp[MAXN];
 
int main(int argc, char const *argv[])
{
    sieve();
 
    ll n,x;
    cin >> n;
 
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
 
   /* FOR(i,1,50)
    {
        trace2(i,prime[i]);
    }   
    cout <<endl;*/
    FOR(i,3,n)
    {
        dp[i] = LLONG_MAX;
        x = i;
        while(prime[x] != 0 && x > 1)
        {
            dp[i] = min(dp[i],dp[i-prime[x]]+1);
            x /= prime[x];
        }
 
        //trace3(dp[i],i,x);
        if(x != 1)
        {
            dp[i] = min(dp[i], dp[i-x]+1);
        }
    }
 
    cout << dp[n] << endl;
 
    return 0;
} 