#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define SL(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define MAX 10000000
#define MOD 1000000007
#define endl "\n"
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())

ll n;

map< pair<ll,ll> , ll> dp;
std::vector<ll> v;

ll func(ll x,ll y)
{
    if(x>y)
        return -LLONG_MAX;
    if(dp[make_pair(x,y)]!=0)
        return dp[make_pair(x,y)];

    ll max = std::max(func(x+1,y),func(x,y-1));
    ll val =  v[y] - v[x-1];
    val = std::max(max,val);

    dp[make_pair(x,y)] = val;
    return val;
}

int main()
{
    BOOST;
    ll m;
    cin>>n;
    
    v.pb(0);
    ll x;
    FOR(i,0,n)
    {
        cin>>x;
        v.pb(x + v[v.size()-1]);
    }

    cin>>m;
    while(m--)
    {
        ll y;
        cin>>x>>y;
        if(x>y)
            swap(x,y);
        cout<<func(x,y)<<endl;
    }

    return 0;
}