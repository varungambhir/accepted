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
#define L 2*stIndex
#define R 2*stIndex+1
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define MAXN 100005
#define MOD 1000000007

ll tree[4*100010];
ll lazy[4*100010];

void lazyme(pair<ll,ll> &p, ll &stIndex)
{
    ll mid = (p.F + p.S)/2;
    if(lazy[stIndex] != 0)
    {
        tree[stIndex] += lazy[stIndex];
        if(p.F != p.S)
        {
            lazy[L] += ( lazy[stIndex]/(p.S - p.F + 1) )*(mid - p.F + 1);
            lazy[R] += ( lazy[stIndex]/(p.S - p.F + 1) )*(p.S -(mid+1)+1);
        }
        lazy[stIndex] = 0;
    }
}

void update(pair<ll,ll> p,ll lo,ll hi,ll stIndex,ll value)
{
    ll mid = (p.F+p.S)/2;

    lazyme(p,stIndex);

    if(p.S < lo || p.F > hi)
        return;

    if(p.F >=lo && p.S <=hi)
    {
        if(p.F == p.S)
            tree[stIndex] += value;
        else
        {
            tree[stIndex] += value*(p.S - p.F + 1);
            lazy[L] += value*(mid - p.F + 1);
            lazy[R] += value*(p.S - (mid+1) +1);
        } 
    }
    else
    {
        update( mp(p.F,mid),lo,hi, L , value);
        update( mp(mid+1,p.S),lo,hi, R, value);

        tree[stIndex] = tree[L] + tree[R];
    }
}

ll query(pair<ll,ll> p,ll lo,ll hi,ll stIndex)
{
    ll mid = (p.F + p.S)/2;
    lazyme(p,stIndex);

   // cerr << " Q: " << p.F << " " << p.S << "  " << tree[stIndex] << endl;
    
    if(p.F>=lo && p.S<=hi)
        return tree[stIndex];

    if(mid < lo)
        return query( mp(mid+1, p.S),lo,hi, R);
    if(hi <= mid )
        return query(mp(p.F,mid), lo,hi, L);

    ll qrl = query(mp(p.F,mid),lo,hi, L);
    ll qrr = query(mp(mid+1,p.S),lo,hi, R);

    return qrr + qrl;
}


int main(int argc, char const *argv[])
{
    BOOST;
    int t;
    cin>>t;
    ll v;
    while(t--)
    {
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        ll n,c;
        cin>>n>>c;
        while(c--)
        {
            ll k,p,q;
            cin >> k >> p >> q;
            if(!k)
            {
                cin >> v;
                update(mp(1LL,n),p,q,1LL,v); 
            }
            else
            {
                cout<< query(mp(1LL,n),p,q,1LL) <<endl;
            }
        }
    }

    return 0;
}