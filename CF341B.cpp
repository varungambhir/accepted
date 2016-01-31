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
//#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << "\n"
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
#define MAXN 100010
#define MOD 1000000007

std::vector<ll> v;
map<ll,ll> mp1;
map<ll,ll> mp2;
ll ncr(ll n , ll r )
{
    if(r > n/2)
        r = n-r;
    ll product = 1;

    ll i;

    for(i =  1; i<=r; i++)
    {
        product = product * (n-r+i);
        product = product/i; 
    }
    return product;
}
int main(int argc, char const *argv[])
{
    BOOST;
    ll n,x,y;
    cin >> n;
    FOR(i,1,n)
    {
        cin >> x >> y;
        //a[x][y] = 1;
        //v.push_back(mp(x,y));
        mp1[x+y]++;
        mp2[x-y]++;
    }

    ll ans = 0;
    for(auto &it : mp1)
    {
        //trace2(it.second,ans);
        if(it.second > 1)
        ans += ncr(it.second,2);
        //trace2(it.second,ans);
    }
    for(auto &it : mp2)
    {
        //trace2(it.second,ans);
        if(it.second > 1)
        ans += ncr(it.second,2);
        //trace2(it.second,ans);
    }
    cout << ans <<endl;


    return 0;
}