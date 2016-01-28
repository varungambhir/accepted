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
#define MAXNN 1000010
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

char a[1002][1002];
int n,m,maxcount=0,cnt = 0;
int b[1002][1002]={0};


void floodfill(int i,int j)
{
    if(i>=0 && j>=0 && i<n && j<m)
    {
        if(!b[i][j])
        {
            b[i][j]=cnt;
       //cout<<"[i] "<<i<<" j : "<<j<<" a[i][j] "<<a[i][j]<<" b[i][j]"<<b[i][j]<<"\n";
            if(a[i][j]=='N')
                floodfill(i-1,j);
            else if(a[i][j]=='S')
                floodfill(i+1,j);
            else if(a[i][j]=='E')
                floodfill(i,j+1);
            else if(a[i][j]=='W')
                floodfill(i,j-1);

            b[i][j]=cnt;
            return;
        }
        else
        {
            cnt=b[i][j];
            return;
        }
    }
    return;
}
int main()
{
    //inputfile();
    cpp_input();
    cin>>n;
    cin>>m;
    F(i,0,n)
    cin>>a[i];

    F(i,0,n)
    {
        F(j,0,m)
        {
            if(!b[i][j])
            {
                cnt=maxcount+1;
                floodfill(i,j);
                if(maxcount < cnt)
                    maxcount++;

            }

        }
    }
    printf("%d\n",maxcount);
    return 0;
}

