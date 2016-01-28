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
#define F1 first
#define S2 second
#define Lf 2*r
#define Rg 2*r+1
//vector< vector<int> >Matrix(N, vector<int>(M,0));
#define gc getchar_unlocked
#define MAXNN 10000100
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
int A[100001][11]={0};//10th for determining sqfree or not

void func()
{
    int i,j,k,temp;
    A[0][0]=1;
    REP(i,2,316)
    {
        if(A[i][10]==0)
        {
            k = i*i;
            for(j=k;j<100001;j=j+k)
            {
                A[j][10]=1;//not included
            }
        }
    }

    for ( i = 0; i < 100001; ++i)
    {
        if(A[i][10]==0)
        {
            temp=i;
            while(temp!=0)
            {
                A[i][temp%10]=1;
                temp=temp/10;
            }
            for(j=0;j<10;j++)
            {
                A[i][j]=A[i][j] + A[i-1][j];
            }
        }
        else
        {
             for(j=0;j<10;j++)
            {
                A[i][j]= 0 + A[i-1][j];
            }
        }
    }
return;
}


int main()
{
    inputfile();
    cpp_input();
    //freopen("output.in","w",stdout);
    func();
    int t;
    scanint(t);
    while(t--){
    int low,high,d;
    scanint(low);scanint(high),scanint(d);
    printf("%d\n",A[high][d]-A[low-1][d]);
    }
    return 0;
}
