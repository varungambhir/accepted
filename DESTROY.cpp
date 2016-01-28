#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
//#define mp make_pair
#define F first
#define S second
#define L 2*stindex
#define R 2*stindex+1
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/
#define MAXN 50000
#define MOD 1000000007

map<ll,ll>mp;
int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while(t--)
    {
        mp.clear();
        ll n;
        cin >> n;
        FOR(i,1,n)
        {
            ll x;
            cin >> x;
            mp[x]++;
        }
        ll maxi = 0;
        for(auto &it : mp)
        {
            ll x = it.second;
            maxi = max(maxi,x);
        }
        if( (maxi*2)<= n)
            cout << (n+1)/2 << endl;
        else
            cout << maxi <<endl;
    }
    return 0;
}
