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
#define present_mapset(c,x) ((c).fparent(x) != (c).end())
#define cpresent_vector(c,x) (fparent(all(c),x) != (c).end())
#define repstl(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define matrix vector< vector<ll> >
//#define PI acos(-1.0)
#define PI 3.141592653589793
#define EPS 1e-9
#define F1 first
#define S2 second
#define Lf 2*r
#define Rg 2*r+1
//vector< vector<int> >Matrix(N, vector<int>(M,0));
#define gc getchar_unlocked
#define MAXNN 100010
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
ll gcd (ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}
char str[125];
int main()
{
    inputfile();
    while(scanf("%s",str)==1 && strcmp(str,"0"))
        {
            int len =strlen(str)-5;
            ll ansu, ansd=999999999999999999LL;
            F(i,0,len)
            str[i]=str[i+2];

            F(i,0,len)
            {
                ll d = 1, u =0;
                F(j,0,i)
                {
                    d = d*10;//d=d*10
                    u = u*10 + str[j] - 48;
                }

                ll x=0,y=0;//rhs

                F(j,i,len)
                {
                    x = x*10 + str[j]-48;//rhs number
                    y = y*10 + 9;
                }
                d = d * y;
                u = u * y + x;

                ll g =gcd(d,u);

                u = u/g;

                d = d/g;

                if(d<ansd)
                {
                    ansd=d;
                    ansu=u;
                }

            }

            printf("%lld/%lld\n",ansu,ansd);
        }
    return 0;
}
