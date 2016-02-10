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

inline void inputfile()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
}

 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun

And you run and you run to catch up with the sun
But it's Sinking
Racing around to come up behind you again
The Sun is the same in a relative way, but you're older
Shorter of breath and one day closer to death

Every year is getting shorter, never seem to find the time
Plans that either come to naught or half a page of scribbled lines
- Time, Pink Floyd*/

#define MAXN 10000010
#define MOD 1000000007
#define PD 0
#define AD 1

double dp[1010][1010][2] = {{{0}}} ;

bool vis[1010][1010][2] = {{{0}}} ;

double B[1010][1010], S[1010][1010];

bool check = 0;

ll n, m;
double d;
ll const INF = (ll)1e18;

//DP[t][i][c] denotes the maximum money 
//that you can have in currency 'cur' if 
//you are at kiosk  i  at the end of t seconds

double rec(ll i,ll t,bool c)
{
    if(check || i<0 || i>=n || (t==m && c== AD) )
        return 0.0;
    if(t>=m)
        return (d);

    if(vis[i][t][c])
        return dp[i][t][c];

    double ans = 0.0;

    if(c == AD)
    {
        ans = max(ans,  B[i][t]*rec(i,t+1,PD)  );
        ans = max(ans,  rec(i,t+1,AD)  );
        ans = max(ans,  rec(i+1,t+1,AD)  );
        ans = max(ans,  rec(i-1,t+1,AD)  );
    }
    else// if(c == PD)
    {
        ans = max(ans,  (1.0/S[i][t])*rec(i,t+1,AD)  );//convert to AD
        ans = max(ans,  rec(i,t+1,PD)  );
        ans = max(ans,  rec(i+1,t+1,PD)  );
        ans = max(ans,  rec(i-1,t+1,PD)  );
    }

    if(ans > INF)
    {
        check = 1;
    }

    vis[i][t][c] = 1;
    return dp[i][t][c] = ans;

}

int main(int argc, char const *argv[])
{
    inputfile();

    cin >> n >> m >> d;
    FOR(i,0,n-1)
    FOR(j,0,m-1)
    cin >> S[i][j] >> B[i][j];

    double ans = 0;

    FOR(i,0,n-1)
    ans = max(ans,rec(i,0,PD));

    if(check)
    {
        cout << "Quintillionnaire\n";
    }
    else
    {
        printf("%.6f\n", ans);
    }

    return 0;
}
