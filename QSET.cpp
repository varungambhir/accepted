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
/*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/
#define MAXN 100010
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
    int l, r ;
    ll cnt;
    int totalsum , suffix[3] , prefix[3] , lazy;
    node()
    {
        FOR(i,0,2) suffix[i] = prefix[i]  = 0;
        lazy = cnt = totalsum = 0;
    }
};

struct node segtree[MAXN<<3];
int arr[MAXN<<3];
int maxi = -1;
void error(int index)
{
    node &p = segtree[index];
    printf("L: %d R: %d Totalsum: %d cnt: %lld prefix[ %d %d %d ] suffix[ %d %d %d ] ", 
           p.l,p.r,p.totalsum,p.cnt,p.prefix[0],p.prefix[1],p.prefix[2],p.suffix[0],p.suffix[1],p.suffix[2]
           );
      if(p.l == p.r)
        printf("Val: %d",arr[p.l]);
    printf("\n");
}


void lazyme(int index = 1)
{
    return;
}
void merge(node &ptr,const node &left,const node &right)
{
    ptr.cnt = left.cnt + right.cnt;
    FOR(i,0,2)
    FOR(j,0,2)
    if(  (i+j)%3 == 0 )
        ptr.cnt += ((ll)left.suffix[i] * (ll)right.prefix[j]);

    FOR(i,0,2)
    {
        ptr.prefix[i] = left.prefix[i] + right.prefix[ (6 +i -left.totalsum )%3 ];
        ptr.suffix[i] = right.suffix[i] + left.suffix[ (6 +i -right.totalsum)%3 ];
    }

    ptr.totalsum = (left.totalsum + right.totalsum)%3;
}

void assign(int index , int p)
{
    node ptr;
    ptr.prefix[p] = 1;
    ptr.suffix[p] = 1;
    ptr.totalsum = p;
    if(!p) //  p == 0
        ptr.cnt = 1;
    ptr.l = segtree[index].l;
    ptr.r = segtree[index].r;

    segtree[index] = ptr;
}

void build_tree(pair<int,int> p, int index = 1)
{

    struct node &ptr = segtree[index];
    ptr.l = p.F;
    ptr.r = p.S;
    ptr.lazy = 0;

    if(p.F == p.S)
    {
        assign(index,arr[p.F]%3);
        return; 
    }
    else
    {
        int mid = (p.F + p.S)>>1;
        build_tree(mp(p.F,mid),L(index));
        build_tree(mp(mid+1,p.S),R(index));

        merge(segtree[index],segtree[L(index)],segtree[R(index)]);
    }
    //maxi = max(maxi,index);
    //error(index);
}

struct node query(int lo, int hi, int index = 1)
{

    if(lo > hi || segtree[index].l > segtree[index].r)
    {
        node temp;
        return temp;
    }    
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
    p.l = l.l;
    p.r = r.r;
    return p;

}

void update(int lo,int hi , int val , int index = 1)
{
    node &ptr = segtree[index];
    //lazyme(index);
    //out of range
    if( ptr.l > hi || ptr.r < lo || lo > hi )
        return;

    if(lo <= ptr.l && ptr.r <= hi)
    {
        if(ptr.l != ptr.r)
        {
            //lazy propagation
            update(lo,hi,val,L(index));
            update(lo,hi,val,R(index));
            merge(segtree[index],segtree[L(index)],segtree[R(index)]);
            return;
        }
        else
        {
            assign(index,val%3);
            return;
        }
    }
    else
    {
        update(lo,hi,val,L(index));
        update(lo,hi,val,R(index));
        merge(segtree[index],segtree[L(index)],segtree[R(index)]);
    }

}
char s[1000100];
int main(int argc, char const *argv[])
{
    //BOOST;
    int n,m;
    scanint(n);
    scanint(m);
    scanf("%s",s);
    FOR(i,1,n)
    {
        arr[i] = s[i-1] - '0';
    }

    build_tree(make_pair(1,n),1);
    while(m--)
    {
        int c,x, y;
        scanint(c);
        scanint(x);
        scanint(y);
        //cerr << "---------\n";
        if(c == 1)
        {
            arr[x] = y;
            update(x,x,y,1);
        }
        else
        {
            printf("%lld\n",query(x,y,1).cnt );
        }
        
       /* 
        FOR(i,1,maxi)
        {
            error(i);
        }
        */
    }



    return 0;
}
