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
typedef pair<ll,ll> pii;
std::vector<pii> v;
std::vector<ll> arr;
int main(int argc, char const *argv[])
{
    //BOOST;
    ll n,p;
    cin >> n >> p;
    ll l,r;
    ll den = 1;
    FOR(i,0,n-1)
    {
        cin >> l >> r;
        den = den*(r-l+1LL);  
        v.push_back(make_pair(l,r));
    }

    
    ll l2,r2;
    l2 = v[0].first;
    r2 = v[0].second;

    v.push_back(make_pair(l2,r2));

    double x,y;
    double ans = 0;
    double M, N;
    FOR(i,0,n-1)
    {

        l = v[i].first;
        r = v[i].second;

        l2 = v[(i+1)].first;
        r2 = v[(i+1)].second;

        M = r-l+1;
        N = r2-l2+1;

        x = r/p - (l-1)/p; 
        y = r2/p - (l2-1)/p;

      //  trace5(ans,M,x,N,y);
        ans = ans + 1- ((M-x)/M)*((N-y)/N);  
        //c = 0;
    }

    //trace1(ans);
    //ans /= den;
    ans = ans *2000;
    printf("%.6lf\n",ans);

    return 0;
}