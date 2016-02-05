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

typedef pair<int,int> pii;
ll n;
ll v[MAXN] , c[MAXN];
ll dp[MAXN];

//http://www.codeforces.com/contest/264/problem/C
main(int argc, char const *argv[])
{
    BOOST;
    ll  a,b,q;
    cin >> n >> q;
    FOR(i,1,n)
    {
        cin >> v[i];
    }
    FOR(i,1,n)
    {
        cin >> c[i];
    }

    while(q--)
    {
        cin >> a >> b;
        //memset(dp,0,sizeof(dp));
        FOR(i,0,n+2) dp[i] = LLONG_MIN;
        pair<ll,ll> largest, secondlargest;// min value is 0 not LLONG_MIN
        secondlargest = largest = make_pair(0,-1);
        ll w;
        ll ans = 0;
        FOR(i,1,n)
        {
            if(dp[c[i]] != LLONG_MIN)
                dp[c[i]] = max(dp[c[i]], dp[c[i]] + v[i]*a);

            dp[c[i]] = max(dp[c[i]],v[i]*b);
            //cannot consider 0 for w
            //2 
            //w = 0;//base 1
            if(largest.S != c[i])
            {   
                w = largest.F + v[i]*b;//prev non 3
            }
            else if(secondlargest.S != c[i])
            {
                w =secondlargest.F + v[i]*b;
            }

            dp[c[i]] = max(dp[c[i]],w);

            if( largest.S == c[i])
            {
                largest.F = max(largest.F ,dp[c[i]]);
            }
            else if(secondlargest.S == c[i])
            {
                secondlargest.F = max(secondlargest.F, dp[c[i]]);
            }
            else if(dp[c[i]] > largest.F)
            {
                secondlargest = largest;
                largest.F = dp[c[i]];
                largest.S = c[i];               
            }
            else if(dp[c[i]] > secondlargest.F)
            {
                secondlargest.F = dp[c[i]];
                secondlargest.S = c[i];
            }

            if(largest.F < secondlargest.F)
                swap(largest,secondlargest);

            ans = max(ans,dp[c[i]]);
        }
        
        cout << ans <<"\n";
    }
    return 0;
}