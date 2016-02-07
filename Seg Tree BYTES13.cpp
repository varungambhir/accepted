/*
Written by : Ashish Sareen
*/
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

And you run and you run to catch up with the Sun but it's sinking
Racing around to come up behind you again
The Sun is the same in a relative way, but you're older
Shorter of breath and one day closer to death

Every year is getting shorter, never seem to find the time
Plans that either come to naught or half a page of scribbled lines
- Time, Pink Floyd*/

#define MAXN 10000010
#define MOD 1000000007

typedef pair<ll,ll> pii;

inline int getans(ll n)
{
    if( !(n & (n-1LL)) )
        return 1;
    return 0;
}

struct node
{
    ll l, r , sum;
    ll lazy;
};
struct node segtree[1<<21];
ll arr[1<<21];

void error(ll index)
{
    node &p = segtree[index];
    trace5(index, p.l, p.r , p.sum , p.lazy);
}

void build_tree(pii p ,ll index = 1)
{
    segtree[index].l = p.F;
    segtree[index].r = p.S;
    segtree[index].lazy = 0;

    if(p.F  == p.S)
    {
        segtree[index].sum = getans(arr[p.F]);
    }
    else
    {
        ll mid = (p.F + p.S)>>1;
        build_tree(make_pair(p.F,mid) , L(index));
        build_tree(make_pair(mid+1,p.S), R(index));

        segtree[index].sum = segtree[L(index)].sum + segtree[R(index)].sum;
    }
    //error(index);
}

void lazyme(ll index )
{
    node &ptr = segtree[index];

    if(ptr.lazy != 0)
    {
        ptr.sum = (ptr.r - ptr.l + 1)* getans(ptr.lazy);
        if(ptr. l != ptr. r)
        {   
            segtree[L(index)].lazy = ptr.lazy;
            segtree[R(index)].lazy = ptr.lazy;
        }
        ptr.lazy = 0;
    }
}

void update(ll lo, ll hi, ll val, ll index = 1)
{
    node &ptr = segtree[index];

    lazyme(index);

    if( ptr.l > hi || ptr.r < lo) 
        return;

    if(lo <= ptr.l && ptr.r <= hi)
    {
        ptr.sum = (ptr.r - ptr.l + 1) * getans(val);
        if(ptr.r != ptr.l)
        {
          segtree[L(index)].lazy = val;
          segtree[R(index)].lazy = val;   
        }
    }
    else
    {
        update(lo,hi,val,L(index));
        update(lo,hi,val,R(index));
        ptr.sum = segtree[L(index)].sum + segtree[R(index)].sum;
    }
}

node query(ll lo,ll hi,ll index = 1)
{
    node &ptr = segtree[index];
    lazyme(index);

    if(lo <= ptr.l && ptr.r <= hi)
        return segtree[index];

    ll mid = (ptr.l + ptr.r)>>1;

    if(mid < lo)
        return query(lo,hi,R(index));

    if(hi <= mid)
        return query(lo,hi,L(index));

    node p , left, right;

    left = query(lo,hi,L(index));
    right = query(lo,hi,R(index));

    p.sum = left.sum + right.sum;
    p.l = left.l;
    p.r = right.r;

    return p;
}

int main(int argc, char const *argv[])
{
    BOOST;
    ll n,q,x,y,v;
    cin >>n >> q;
    FOR(i,1,n)
    {
        cin >> arr[i];
    }

    build_tree(make_pair(1LL,n),1LL);
    while(q--)
    {
        int z;
        cin >> z;
        if(!z)
        {
            cin >> x >> y >> v;
            update(x+1,y+1,v,1LL);
        }
        else
        {
            cin >> x >> y;
            node ptr = query(x+1,y+1,1LL);
            cout << ptr.sum << endl;
        }   
    }

    return 0;
}