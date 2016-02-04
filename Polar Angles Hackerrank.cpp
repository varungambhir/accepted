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
typedef pair<ll,ll> pii;
const double pi = acos(-1.0);
double angle(const pii &a)
{

   double ans;
   ans = atan2((double)a.S,(double)a.F);
   return ans;
}

ll dist(const pii &a)
{
    return (a.F * a.F + a.S*a.S);
}

struct cmp
{
    bool operator()(const pii &a, const pii &b)
    {
        double a1 = angle(a);
        double b1 = angle(b);
        a1 = a1 < 0.0 ? a1 + pi*2.0 : a1;
        b1 = b1 < 0.0 ? b1 + pi*2.0 : b1;
        if(a1 == b1)
        {
            return dist(a) < dist(b);
        }
        else
        {
            return a1 < b1;
        }
    }
};  

std::vector<pii> v;

int main(int argc, char const *argv[])
{
    BOOST;  
    int n;

    cin >> n;
    FOR(i,1,n)
    {
        int x,y;
        cin >> x >> y;
        v.pb(mp(x,y));
    }
    sort(v.begin(),v.end(),cmp());
    for(auto &it : v)
    {
        double a1 = angle(it);
        a1 = a1 < 0.0 ? a1 + pi*2.0 : a1;
       // trace3(it.F,it.S,a1);
        cout << it.F << " " <<it.S  <<"\n";
    }
    return 0;
}