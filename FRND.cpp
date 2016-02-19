#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%lld",&x)
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

ll arr[1000100];
ll zeros[1000100]={0};
ll ones[1000100]={0};
ll power(ll a,ll p)
{
    ll ret = 1;
    while(p)
    {
        if(p & 1)
            ret = (ret*a);
        a = (a*a);
        p /= 2;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    ll n,m,k,kmax = -1;
    SD(n);
    ll mini, ind;
    mini = -1;
    ind = -1;
    FOR(i,1,n)
    {
        SD(arr[i]);
        if(arr[i] > mini)
        {
            mini = arr[i];
            ind = i;
        }
    }

    k = 0;
    m = mini;
    while(m > 0)
    {
        if(m&1)
        {
            ones[k]++;
        }
        else
        {
            zeros[k]++;
        }
        m = m>>1;
        k++;
    }

    FOR(i,1,n)
    {
        if(i == ind)
            continue;
        m = arr[i];
        FOR(j,0,k-1)
        {
            if(m & 1)
            {
                ones[j]++;
            }
            else
            {
                zeros[j]++;
            }
            m = m >> 1;
        }
    }


    ll p,ans = 0;
    FOR(i,0,k-1)
    {
        m = ones[i];
        p = zeros[i];
        ans += (m*p*power(2,i));
    }

    printf("%lld\n", ans);
    return 0;
}