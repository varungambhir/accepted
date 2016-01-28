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
int L[1100][1100];
int main()
{
    inputfile();
    //cpp_input();
    char a[1100],b[1100];
    while(scanf("%s %s",a,b)==2)
    {
       int m=strlen(a);
       int n=strlen(b);


       F(i,0,m+1)
       {
        F(j,0,n+1)
        {
            if(!i || !j)
                L[i][j]=0;
            else if(a[i-1]==b[j-1])
                L[i][j]=L[i-1][j-1] + 1;
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);
        }
       }
       int ind=L[m][n];
       char lcs[ind+1];
       lcs[ind]='\0';
       int i=m,j=n;
       while(i>0 && j>0)
       {
        if(a[i-1]==b[j-1])
        {
            lcs[ind-1]=a[i-1];
            printf("%c",a[i-1]);
            i--,j--,ind--;
        }
        else if(L[i-1][j]>L[i][j-1])
            i--;
        else
            j--;

       }

       printf("\n");
    }

    return 0;
}
