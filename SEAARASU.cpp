#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L 2*node
#define R 2*node+1
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
#define MAXN 1010
#define MOD 1000000007
std::vector<ll> v;

ll gcd(ll a,ll b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

int main(int argc, char const *argv[])
{
    BOOST;
    ll t;
    cin>>t;
    while(t--)
    {
        v.clear();
        ll n;
        cin>>n;

        FOR(i,0,n)
        {
            ll x;
            cin>>x;
            v.pb(x);
        }

        ll mini = v[0];
        FOR(i,1,n)
        {
            mini = __gcd(v[i],mini);
        }       

        cout<<mini*n<<endl;

    }

    return 0;
}