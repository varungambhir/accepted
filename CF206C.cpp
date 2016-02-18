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
#define MAXN 3000005
#define MOD 1000000007LL



//Problem setter 3*1^6
ll a[MAXN];
ll f[MAXN]={0};
//http://www.codeforces.com/contest/354/problem/C
int main(int argc, char const *argv[])
{
    BOOST;
    ll n , k;
    
    cin >> n >> k;
    
    bool c = 0;
    
    ll mini,maxi;
    
    mini = LONG_MAX;
    maxi = LONG_MIN;

    FOR(i,1,n)
    {
        cin >> a[i];
        f[a[i]]++;
        if(a[i] == 1)
            c = 1;

        mini = min(mini,a[i]);
        maxi = max(maxi,a[i]);
    }
    if(c)
        cout << "1\n";
    else
    {

        FOR(i,1,MAXN)
        f[i] += f[i-1];

        ll gcd = mini;
        if( gcd <= k+1)// gcd is mini
        {
            cout << gcd << endl;
        }
        else
        {
            //k+1 to m
            bool cc = 1;
            ll sum ;
            for(ll i = mini; i>=k; i--)
            {
                sum =0 ;
                for(ll j = 1; j <= maxi/i ; j++)
                {
                    sum = sum +  f[j*i + k] - f[j*i -1];
                }

                if(sum == n)
                {
                    cc = 0;
                    gcd = i;
                    break;
                }
                
            }
            if(cc) gcd = 1;
            cout << gcd << endl;
        }
    }
    return 0;
}