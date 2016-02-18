#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
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
#define MOD 1000000007LL

#define pii pair<ll,ll>

map<ll , multiset< pii        > > songs;
map<ll , multiset<pair< pii,ll> > > actors; //need index too
set< pair < pii , ll > > events; 

ll ans[1000001]; 
int main(int argc, char const *argv[])
{
    BOOST;
    int n;
    cin >> n;

    set<ll> allpoints;
    FOR(i,1,n)
    {
        int c, d;
        cin >> c >> d;
        allpoints.insert(d);
        songs[d].insert({c , i});
    }
    int m; cin >> m;
    FOR(i,1,m)
    {
        int a , b , k;
        cin >> a >> b >> k;
        allpoints.insert(b);
        actors[b].insert({ {a,k}, i });
    }

    for(auto &i : allpoints)
    {
        if(songs[i].empty() == false)
        {
            for(auto &j : songs[i])
            {
                events.insert( { { j.F, i }, j.S } );
            }
        }
        if( actors[i].empty() == false )
        {
            for(auto &j : actors[i])
            {
                ll start = j.F.F;
                ll kk = j.F.S;
                ll index = j.S;
                auto it = events.upper_bound( { {start,-1 },-1 } );
                while(kk > 0 && it!= events.end())
                {
                    kk--;
                    ans[(*it).S] = index;
                    events.erase(it);
                    it = events.upper_bound( { {start,-1 },-1 } );
                }
            }
        }
    }

    if( events.empty())
    {
        cout << "YES\n";
        FOR(i,1,n)
        cout << ans[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "NO\n";
    }






    return 0;
}