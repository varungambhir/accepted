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
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define matrix vector< vector<ll> >
#define F1 first
#define S2 second
#define Lf 2*r
#define Rg 2*r+1
//vector< vector<int> >Matrix(N, vector<int>(M,0));
#define gc getchar_unlocked
#define MAXNN 1000001
#define mod 1000000007

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
int arr[1000002];
void sieve()
{
 memset(arr,0,sizeof(arr));
    int i=2;
int    cube=i*i*i;
    while(cube<1000001)
    {

        for(int j=cube;j<1000001;j=j+cube)
        {
            arr[j]=-1;
        }
        i++;
        cube=i*i*i;
    }
    int k=1;
    for(i=1;i<1000001;i++)
    {
        if(!arr[i])
        arr[i]=k++;
    }
    return;
}

int main()
{
    inputfile();
    //freopen("output.in","w",stdout);
    sieve();
    int t;
    scanint(t);
    F(p,0,t)
    {
        int n; scanint(n);
        if(arr[n]<0)
        printf("Case %d: Not Cube Free\n",p+1);
        else
        printf("Case %d: %d\n",p+1,arr[n]);

    }
    return 0;
}
