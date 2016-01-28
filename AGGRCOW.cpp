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
#define present_vector(c,x) (find(all(c),x) != (c).end())
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
ll gcd(ll a ,ll b)
{
  if(b==0)
  return a;
else
    return gcd(b,a%b);
}
int n,c;
int arr[100100];
int func(int x)
{
    int placed=1;
    ll lastpos=arr[0];
    F(i,1,n)
    {
        if(arr[i]-lastpos>=x)
           { placed++;

        lastpos=arr[i];
            }
                   if(placed==c)
            return 1;
    }
    return 0;

    return 1;//useless
}
int binsearch()
{
    int left=0,right=arr[n-1],mid;

    while(left<right)
    {
        mid = left + (right-left)/2;
        if(func(mid)==1)
        {
            left=mid+1;
        }
        else
        {
            right=mid;
        }
    }
    return left-1;

    return left;//useless 
}
int main(int argc, char const *argv[])
{
    inputfile();
    int t;
    scanint(t);
    while(t--)
    {
        scanint(n);scanint(c);
        F(i,0,n)
        scanint(arr[i]);

        sort(arr,arr+n);
        
        printf("%d\n",binsearch());
    }
    return 0;
}
