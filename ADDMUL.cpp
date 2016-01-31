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
struct node
{
    ll sum; // sum  = E(Ai)
    //mul*A + add
    ll l,r;//range
    ll lazyadd;
    ll lazymulti;
};
struct node segtree[8*MAXN];
ll arr[MAXN];

void error(ll index)
{
    node &p = segtree[index];
    trace6(index,p.l,p.r,p.sum,p.lazyadd,p.lazymulti);
}
//sum => (R-L+1)*VAL + MUL*E(Ai)//sum  where E(Ai) is already stored in sum
//multiply => (R-L+1)*VAL*MUL + MUL*MUL*E(Ai)
void build_tree(pii p,ll index=1)
{
    segtree[index].l = p.F;
    segtree[index].r = p.S;
    node &ptr = segtree[index];
    ptr.lazyadd = 0;
    ptr.lazymulti = 1;
    
    if(p.F == p.S)
    {
        segtree[index].sum = arr[p.F];
        //error(index);
        return;
    }

    ll mid = (p.F + p.S)/2;
    build_tree(mp(p.F,mid),2*index);
    build_tree(mp(mid+1,p.S),2*index+1);

    ptr.sum = (segtree[L].sum + segtree[R].sum)%MOD;
    //error(index);
}

void lazyme(ll index)
{
    node &ptr = segtree[index];
    if(ptr.lazymulti != 1)
    {
        ll val = ptr.lazymulti;

        ptr.sum = (ptr.sum*val)%MOD;
        segtree[L].lazymulti = (segtree[L].lazymulti * val)%MOD;
        segtree[R].lazymulti = (segtree[R].lazymulti * val)%MOD;

        segtree[L].lazyadd = (segtree[L].lazyadd * val)%MOD;
        segtree[R].lazyadd = (segtree[R].lazyadd * val)%MOD;
        ptr.lazymulti = 1;
    }
    if(ptr.lazyadd != 0)
    {
        ll val = ptr.lazyadd;
        ptr.sum = (ptr.sum + (ptr.r - ptr.l +1)*val )%MOD;
        segtree[L].lazyadd  = (segtree[L].lazyadd + val)%MOD;
        segtree[R].lazyadd  = (segtree[R].lazyadd + val)%MOD;
        ptr.lazyadd = 0;
    }
}

void add(ll lo, ll hi,ll val,ll index = 1)
{
    node &ptr = segtree[index];
    lazyme(index);

    //out of range
    if(  ptr.l > hi || ptr.r < lo)
        return;
    //fully in range
    if(ptr.l >= lo && ptr.r<= hi )
    {
        ptr.sum = (ptr.sum + (ptr.r - ptr.l +1)*val)%MOD;
        segtree[L].lazyadd = (segtree[L].lazyadd + val)%MOD;
        segtree[R].lazyadd = (segtree[R].lazyadd + val)%MOD;
    }
    else//partially in range
    {
        add(lo,hi,val,L);
        add(lo,hi,val,R);
        ptr.sum = (segtree[L].sum + segtree[R].sum)%MOD;
    }
}

void multiply(ll lo,ll hi,ll mul,ll index =1)
{
    node &ptr = segtree[index];

    lazyme(index);

    if(ptr.l > hi || ptr.r < lo)
        return;
    if(ptr.l >= lo && ptr.r <= hi)
    {
        ptr.sum = (ptr.sum * mul)%MOD;
        segtree[L].lazymulti = (segtree[L].lazymulti * mul)%MOD;
        segtree[R].lazymulti = (segtree[R].lazymulti * mul)%MOD;

        segtree[L].lazyadd = (segtree[L].lazyadd * mul)%MOD;
        segtree[R].lazyadd = (segtree[R].lazyadd * mul)%MOD;
    }
    else
    {
        multiply(lo,hi,mul,L);
        multiply(lo,hi,mul,R);
        ptr.sum = (segtree[L].sum + segtree[R].sum)%MOD;
    }
}

node query(ll lo, ll hi ,ll index =1)
{
    node &ptr = segtree[index];

    lazyme(index);
    if(lo <= ptr.l && ptr.r <= hi)//lo ptr.l ptr.r hi
        return segtree[index];

    ll mid = (ptr.l + ptr.r)/2;

    if(mid < lo)//R
        return query(lo,hi,R);
    if(hi <= mid)//L
        return query(lo,hi,L);

    node p,pleft,pright;
    pleft = query(lo,hi,L);
    pright = query(lo,hi,R);

    p.sum = (pleft.sum + pright.sum)%MOD;
    p.l = pleft.l;
    p.r = pright.r;
    return p;
}

int main(int argc, char const *argv[])
{
    BOOST;
    ll n,q;
    memset(arr,0,sizeof(arr));
    cin >> n >> q;
    FOR(i,1,n)
        cin >> arr[i];
    build_tree(make_pair(1,n),1);

    FOR(i,1,q)
    {
        ll z,x,y,v;
        cin >> z >> x >> y;
        if(z != 4)
        cin >> v;

        switch(z)
        {
            case 1:   add(x,y,v);
                      break;

            case 2:   multiply(x,y,v);
                      break;

            case 3:   multiply(x,y,0);
                      add(x,y,v);
                      break;

            case 4:   node ptr = query(x,y,1);
                      cout << ptr.sum << "\n";
                      break;
        }
    }
    return 0;
}



