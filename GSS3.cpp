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

#define MAXN 50005
#define MOD 1000000007

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


typedef pair<int,int> pii;
struct node
{
    int l, r;
    int sum , maxsum , suffixMaxsum , prefixMaxsum , lazy;
    node()
    {
        sum = maxsum = suffixMaxsum = prefixMaxsum = lazy = -1000000;
    }
};

struct node segtree[MAXN<<4];
int arr[MAXN<<4];

void error(int index)
{
    node &p = segtree[index];
    //trace6(index, p.l, p.r , p.sum ,p.suffixMaxsum,p.prefixMaxsum );
}


void lazyme(int index = 1)
{
    //Not needed for single point updates
    return;
}
void merge(node &ptr,const node &left,const node &right)
{
    ptr.l = left.l;
    ptr.r = right.r;

    ptr.sum = left.sum + right.sum;

    ptr.prefixMaxsum = max( left.prefixMaxsum, left.sum + right.prefixMaxsum);
    ptr.suffixMaxsum = max(right.suffixMaxsum, right.sum + left.suffixMaxsum);
    ptr.maxsum = max(ptr.prefixMaxsum,ptr.suffixMaxsum) ;
    ptr.maxsum = max(ptr.maxsum,max(ptr.sum , left.suffixMaxsum + right.prefixMaxsum));
    ptr.maxsum = max(ptr.maxsum,max(left.maxsum,right.maxsum));
}


void build_tree(pair<int,int> p, int index = 1)
{

    struct node &ptr = segtree[index];
    ptr.l = p.F;
    ptr.r = p.S;
    ptr.lazy = 0;

    if(p.F == p.S)
    {
        ptr.sum = ptr.maxsum = ptr.prefixMaxsum = ptr.suffixMaxsum = arr[p.F];
        return;
    }

    int mid = (p.F + p.S)>>1;
    build_tree(make_pair(p.F,mid),L(index));
    build_tree(make_pair(mid+1,p.S),R(index));

    merge(segtree[index],segtree[L(index)],segtree[R(index)]);
    ptr.l = p.F;
    ptr.r = p.S;
}

struct node query(int lo, int hi, int index = 1)
{

    struct node &ptr = segtree[index];
    //lazyme(index);

    if(lo <= ptr.l && ptr.r <= hi)
    {
        return segtree[index];
    }

    int mid = (ptr.l + ptr.r) >> 1;

    if(mid < lo)
    {
        return query(lo,hi,R(index));
    }
    if( hi <= mid)
    {
        return query(lo,hi,L(index));
    }

    node l = query(lo,hi,L(index));
    node r = query(lo,hi,R(index));
    node p;
    merge(p,l,r);
    return p;

}

void update(int lo,int hi , int val , int index = 1)
{
    node &ptr = segtree[index];
    //lazyme(index);
    //out of range
    if( ptr.l > hi || ptr.r < lo )
        return;

    if(lo <= ptr.l && ptr.r <= hi)
    {
        if(ptr.l != ptr.r)
        {
            //lazy propagation
            update(lo,hi,val,L(index));
            update(lo,hi,val,R(index));
            merge(segtree[index],segtree[L(index)],segtree[R(index)]);    
        }
        else
        {
            ptr.sum = ptr.maxsum = ptr.prefixMaxsum = ptr.suffixMaxsum = val;   
        }
    }
    else
    {
        update(lo,hi,val,L(index));
        update(lo,hi,val,R(index));
        merge(segtree[index],segtree[L(index)],segtree[R(index)]);
    }

}

int main(int argc, char const *argv[])
{
    //BOOST;
    int n;
    scanint(n);
    FOR(i,1,n)
    scanint(arr[i]);

    build_tree(make_pair(1,n),1);
    int m;
    scanint(m);
    while(m--)
    {
        int c,x, y;
        scanint(c);
        scanint(x);
        scanint(y);
        if(c)
        {
            printf("%d\n",query(x,y).maxsum);
        }
        else
        {
            update(x,x,y,1);
        }
        
    }

    return 0;
}
