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

#define MOD 1000000007

/*
void update(double *tree,int idx,int val)
{
    for(;idx <= maxval; idx = idx + (idx & (-idx)) )
    {
        tree[idx] += val;
    }
}

double queryfenwick(double *tree,int idx)//sum 1...idx
{
    double sum = 0;
    for(;idx <= maxval ; idx = idx - (idx & (-idx)))
    {
        sum += tree[idx];
    }
    return sum;
}

double query(int p)
{
    return queryfenwick(t1, p)*p - queryfenwick(t2, p);
}

double rangequery(int b,int a = 1)// b,a
{
    return query(b) - query(a-1);
}
*/

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

int arr[4*100000];


//https://www.hackerrank.com/contests/womens-codesprint/challenges/mars-and-the-binary-search-tree
int main(int argc, char const *argv[])
{
    
    int n; scanint(n);
    FOR(i,1,n)
        scanint(arr[i]);

    map<pair<ll,ll> , ll>mymap;
    map<pair<ll,ll> , ll>::iterator itt;

    set<ll> bst,myn,myset;

    set<ll>::iterator it;

    mymap[make_pair(INT_MIN,INT_MAX)] = 1;

    ll l,index,r;

    FOR(i,1,n)
    {
        myset.insert(arr[i]);
        it = myset.find(arr[i]);
        if(it == myset.begin())
            l = INT_MIN;
        else
        {
            it--;
            l = *it;
            it++;
        }
        it++;
        if(it == myset.end())
        {
            r = INT_MAX;
        }   
        else
            r = *it;
        index = mymap[mp(l,r)]; 

        mymap.erase(mp(l,r));

        mymap[mp(l,arr[i])] = (index+index)%MOD;
        mymap[mp(arr[i],r)] = (index+index+1LL)%MOD;

        cout << index << " ";

    }
    cout << "\n";

    return 0;
}