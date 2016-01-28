#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define F first
#define S second
#define L 2*node
#define R 2*node+1
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define gc getchar_unlocked
    template <typename T>
void scanint(T &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
#define MAX 1010
#define MOD 1000000007


int main(int argc, char const *argv[])
{
    int t,n;
    scanint(t);
    ll g,s;
    std::vector<ll> v;
    while(t--)
    {
        v.clear();
        scanint(g);scanint(n);
        s = 2;
        for(ll i = 0;i<n-1;i++)
        {
            printf("%lld ",( (s)*g));
        }
        //s = 2;
        
            printf("%lld ",( (s+1)*g));
        printf("\n");
    }
    
    return 0;
}