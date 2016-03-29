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


ll maxVal;
ll tree1[(int)1e6+10];
ll tree2[(int)1e6+10];

void update(ll *tree,int idx,ll val)
{
    while(idx <= maxVal)
    {
        tree[idx] += val;
        idx += (idx & (-idx));
    }
}


void update(int a, int b , ll v)
{
    update(tree1,a,v);
    update(tree1,b+1,-v);
    update(tree2,a,v*(a-1));
    update(tree2,b+1, -v*b);
}


ll read(ll *tree,int idx)
{   
    ll sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

//sum A[1 ... b]
ll read(ll p)
{
    return read(tree1,p)*p - read(tree2,p);
}

//sum A[a ... b]
ll read(int a,int b)
{
    return read(b) - read(a-1);
}

//range update and range queries

int main(int argc, char const *argv[])
{
    //BOOST;
    int t;
    SD(t);
    while(t--)
    {
        int n,c;
        SD(n);
        SD(c);
        maxVal = n+3;
        memset(tree2,0,sizeof(tree2));
        memset(tree1,0,sizeof(tree1));
        while(c--)
        {
            int x;
            SD(x);

            if(x == 0)
            {
                int p,q,v;
                SD(p);SD(q);SD(v);
                update(p,q,v);
            }
            if(x == 1)
            {
                int p,q;
                SD(p);SD(q);
                ll ans = read(p,q);
                //trace1(ans);
                cout << ans << endl;
            }
        }
    }
    return 0;
}