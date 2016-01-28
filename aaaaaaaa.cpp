#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define Sd(x) scanf("%d",&x)
#define F first
#define S second
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define MAX 100010
#define MOD 1000000007
#define endl "\n"
typedef pair<int,int> pii;
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
ll parent[MAX];
int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    //inputfile();
    ll n,k,s,d;

    for(ll i=0; i<MAX; i++)
    {
        parent[i] = i;
    }

    scanint(n);
    scanint(k);
    FOR(i,1,n)
    {
        scanint(s);
        scanint(d);
        parent[d]=s;
    }
    ll count = 0;
    ll p=1;
    ll node;
    for(ll i =1;i<=n;i++)
    {
        if(parent[i]==i) continue;
        node = d = i;
        while(parent[d]!=d)
        {
            p = parent[d]*node;
            //debug(d);
            //debug(p);
            if(p<=k)
                count++;
            d = parent[d];
        }

    }

    printf("%lld\n",count );

    return 0;
}

