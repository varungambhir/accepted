#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define SL(x) scanf("%lld",&x)
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


#define MODD 1000000007
#define MAXN 100100


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

ll a1 , b1 , C, n;



struct node
{
    ll l,r;
    ll maxi;
    ll ans;
};
struct node segtree[MAXN*9];
int a[MAXN*9];

void build_tree(pii p,int index = 1)
{
    node &ptr = segtree[index];
    ptr.l = p.first;
    ptr.r = p.second;
    //ptr.elazy = ptr.olazy = 0;
    ptr.ans = 0;
    if(p.first == p.second)
    {   
        ptr.maxi = a[p.first];
        ptr.ans = 1;        
    }   
    else
    {
        int mid = (p.first + p.second)/2;
        build_tree( {p.first,mid}, L(index) );
        build_tree( {mid+1,p.second} , R(index));

        ptr.maxi = max(segtree[L(index)].maxi ,segtree[R(index)].maxi);
    }

}

/*void lazyme(int index = 1)
{
    //no need in point update
    node &ptr = segtree[index];
    if( ptr.olazy != 0 )
    {
;
    }
    if(ptr.elazy != 0)
    {
;
    }
}*/
/*
void update(int lo,int hi,int val,int index = 1)//val ->swap
{

    //trace1(index);
    node &ptr = segtree[index];
    //lazyme(index);

    if(ptr.l > hi || ptr.r < lo)
        return;
    //completely outisde

    //completely inside
    if(lo <= ptr.l && ptr.r <= hi)
    {
        if(val & 1)
        {
            ptr.even = 0;
            ptr.odd = 1;
        }
        else
        {
            ptr.odd = 0;
            ptr.even = 1;
        }
    }
    else// partial
    {
        update(lo,hi,val,L(index));
        update(lo,hi,val,R(index));
        ptr.even = segtree[L(index)].even + segtree[R(index)].even;
        ptr.odd = segtree[L(index)].odd + segtree[R(index)].odd;
    }
}*/


node query(int lo,int hi,int index = 1)
{

    //trace1(index);
    node &ptr = segtree[index];

    //lazyme(index);

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
    ans.maxi = max(left.maxi,right.maxi);



    return ans;
}



int main(int argc, char const *argv[])
{
    //BOOST;
    int n,q;
    scanint(n); scanint(q);
    FOR(i,1,n)
    {
        scanint(a[i]);
    }

    int a1,b1,c1;
    while(q--)
    {
        scanint(a1);scanint(b1);scanint(c1);
        int ans = 0;

        FOR(i,a1,b1)
        {
            if(a[i] <= c1) ans++;
        }

        printf("%d\n",ans);

    }

    return 0;
}