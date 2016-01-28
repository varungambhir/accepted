#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FF(i,a,n) for(i=(a);i<(n);++i)
#define REP(i,a,n) for(i=(a);i<=(n);++i)
#define V(x) vector<x>
#define Sd(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define all(c) c.begin(), c.end()
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define cpresent_vector(c,x) (find(all(c),x) != (c).end())
#define repstl(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define matrix vector< vector<ll> >
#define PI acos(-1.0)
#define EPS 1e-9
#define F1 first
#define S2 second
#define Lf 2*r
#define Rg 2*r+1
//vector< vector<int> >Matrix(N, vector<int>(M,0));
#define gc getchar_unlocked
#define MAXNN 1000100
#define mod 1e9+7

inline void inputfile() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
}
inline void cpp_input()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);}
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

struct Orderno
{
    int st,p,f;
    bool operator < (const Orderno& str) const
    {
        if (st!=str.st)
            return (st<str.st);
        if (f!=str.f)
            return (f<str.f);
        return (p<str.p);
    }
}a[MAXNN];
int n;
ll dp[MAXNN];//max profit
int index_of(int,int);

int main()
{
    inputfile();
    int t;
    scanint(t);
    while(t--)
    {
        int f,st,d,p;
        scanint(n);
        F(i,0,n)
        {
            scanint(a[i].st);
            scanint(d);
            scanint(a[i].p);
            a[i].f=a[i].st+d;
        }
        sort(a,a+n);

        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=max(dp[i+1],dp[ index_of(i,n) ] + a[i].p );
        }

        printf("%lld\n",dp[0]);

    }

    return 0;
}

int index_of(int low,int high)
{
    if(low==n-1)
    return n;

    int i=low;
    int mid;

    while(low < high)
    {
        mid = (high+low)/2;

        if(a[mid].st>=a[i].f) //p(mid)==true
            high = mid;
        else
            low = mid+1;

    }

    //if((a[low].st>a[i].f))
    //cout<<"Error\n";

    return low;

}
