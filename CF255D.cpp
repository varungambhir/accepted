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
#define MAXN 100005
#define MOD 1000000007


ll fun(ll n){
    return n*n;
}

ll sum(ll w, ll h, ll l){
    ll n = w + h - l;
    if(n > 0) return ((1 + n) * n)/2;
    return 0;
}

ll cal(ll n, ll x, ll y, ll t){

    ll ans = t * t + (t + 1) * (t + 1); //cout << "total = " << ans <<endl;

    ll u = t - (x - 1); //cout << "u = " << u <<endl;
    ll d = t - (n - x); //cout << "d = " << d <<endl;
    ll l = t - (y - 1); //cout << "l = " << l <<endl;
    ll r = t - (n - y); //cout << "r = " << r <<endl;

    if(u > 0) ans -= fun(u);
    if(d > 0) ans -= fun(d);
    if(l > 0) ans -= fun(l);
    if(r > 0) ans -= fun(r);

    if (u > 0 && l > 0) ans += sum(u, l, t + 1);
    if (d > 0 && l > 0) ans += sum(d, l, t + 1);
    if (u > 0 && r > 0) ans += sum(u, r, t + 1);
    if (d > 0 && r > 0) ans += sum(d, r, t + 1);

    return ans; //cout << "ans = " << ans <<endl;
}

ll bsearc(ll n, ll x, ll y, ll c){
    ll l = 0, h = 2 * n + 1, m;
    while(l < h){
        m = (l + h) / 2; //cout << endl << "m = " << m << endl;
        if(cal(n, x, y, m) < c) l = m + 1;
        else h = m;
    }
    return l;
}

int main(){
    ll n, x, y, c;
    cin >> n >> x >> y >> c;
    cout << bsearc(n, x, y, c) << endl;
    return 0;
}