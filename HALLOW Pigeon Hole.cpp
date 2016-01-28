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
#define MAXNN 1e14
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
int a[100005],ind[100005];
int main()
{
    inputfile();
    //cpp_input();
    int c,n;
    ll sum;
    while(1)
    {
        scanint(c);
        scanint(n);
        if(!c)
            break;
        //Pigeon Hole Concept
        
        F(i,0,n)
        {
            scanint(a[i]);
        }
        sum=0;
        memset(ind,-1,sizeof(ind));
        ind[0]=0;//visited before anythng else

            F(i,0,n){
            sum = (sum + a[i])%c;
            if(ind[sum]!=-1)
            {
                printf("%d",ind[sum]+1);//ak+1 ....al
                                         //a1 .... ak a1....al
                for(int j=ind[sum]+2;j<=i+1;++j)
                printf(" %d",j);
                printf("\n");
                break;
            }
            else
                ind[sum]=i+1;


        }

    }
    return 0;
}
