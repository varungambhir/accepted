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
int bsearch(int *a,int left,int right,int value)
{
    int middle;
    while(left!=right)
    {
        middle = (left + right)/2;
        if(a[middle]>=value)
            right=middle;//not middle-1
        else
            left = middle+1;
    }
    return left;//or right
}
int steps(int arr[],int n)
{
    int sorted[n];
    int help_ind[n];

    F(i,0,n)
    sorted[i]=arr[i];

    sort(sorted,sorted+n);

    F(i,0,n)
    {
        help_ind[ bsearch(sorted,0,n-1,arr[i]) ] = i;
    }

    int cnt=1;
    int prev=0;

    F(i,1,n)
    {

        if(help_ind[i]>help_ind[i-1])
            cnt++;

        else if(cnt>prev)
        {
            prev=cnt;
            cnt=1;
        }
    }
    if(cnt>prev)
        prev = cnt;

    return (n-prev);
}
int main() {
   inputfile();
   int t;
   scanint(t);
   while(t--)
   {
    int n;
    scanint(n);
    int arr[n];
    F(i,0,n)
    scanint(arr[i]);
    printf("%d\n",steps(arr,n));

   }
    return 0;
}
