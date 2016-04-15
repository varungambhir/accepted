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

typedef pair<int,int> pii;

struct node
{   
    int l,r;
    int lazy;
    int val;
    node()
    {
        lazy = val = 0;
    }
};
struct node segtree[100100*8];
int arr[100100*8]={0};

void error(int index)
{
    node &p = segtree[index];
    trace5(index, p.l, p.r , p.val , p.lazy);
}

void build_tree(pair<int,int> p,int index = 1)
{
    //trace1(index);
    segtree[index].l = p.first;
    segtree[index].r = p.second;
    segtree[index].lazy = 0;

    if(p.first == p.second)
    {
        segtree[index].val = arr[p.first];
        return;
    }
    else
    {
        int mid = (p.first + p.second)/2;
      //  trace4(mid,p.F,p.S,index);
        build_tree( make_pair(p.first , mid) , L(index));
        build_tree( make_pair(mid+1 , p.second) , R(index));

        segtree[index].val = segtree[L(index)].val + segtree[R(index)].val;
    }
}

void lazyme(int index)
{
    node &ptr = segtree[index];

    if(ptr.lazy != 0)
    {
        ptr.val = (ptr.r - ptr.l + 1) - ptr.val;//lazy
        if(ptr.l != ptr.r)
        {                            //2 flips same value
            segtree[L(index)].lazy = !segtree[L(index)].lazy;
            segtree[R(index)].lazy = !segtree[R(index)].lazy;
        }

        ptr.lazy = 0;
    }
}

void update(int lo,int hi,int index = 1)//val ->swap
{

    //trace1(index);
    node &ptr = segtree[index];
    lazyme(index);

    if(ptr.l > hi || ptr.r < lo)
        return;
    //completely outisde

    //completely inside
    if(lo <= ptr.l && ptr.r <= hi)
    {
        ptr.val = (ptr.r - ptr.l + 1) - ptr.val;
        if(ptr.l != ptr.r)
        {
         segtree[L(index)].lazy = !segtree[L(index)].lazy;
         segtree[R(index)].lazy = !segtree[R(index)].lazy;
        }
    }
    else// partial
    {
        update(lo,hi,L(index));
        update(lo,hi,R(index));
        ptr.val = segtree[L(index)].val + segtree[R(index)].val;
    }
}


node query(int lo,int hi,int index = 1)
{

    //trace1(index);
    node &ptr = segtree[index];

    lazyme(index);

    if(lo <= ptr.l && ptr.r <= hi)
        return segtree[index];

    int mid = (ptr.l + ptr.r)/2;

    if(mid >= hi)
        return query(lo,hi,L(index));

    if(mid < lo)
        return query(lo,hi,R(index));

    node left = query(lo,hi,L(index));
    node right = query(lo,hi,R(index));

    node ans;

    ans.l = left.l; ans.r = right.r;
    ans.val = left.val + right.val;

    return ans;
}

int main(int argc, char const *argv[])
{
    BOOST;
    int n, q;
    cin >> n >> q;
    build_tree(make_pair(0,n-1),1);
    while(q--)
    {
        int c , a,b;
        cin >> c >> a >> b;
        if(c)
        {
            cout << query(a,b,1).val << "\n";
        }
        else
        {
            update(a,b,1);
        }
    }

    return 0;
}