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

#define LEFT 10
#define UP -20
#define Up_Left 4475

int L[110][110],lcss[110][110];
char lcs[110], aa[110],bb[110];
int p;
void scs(int n,int m)
{
    memset(lcss,0,sizeof(lcss));
    int i,j;
    REP(i,0,110)
    {
    L[0][i]=L[i][0]=0;
    }
    REP(i,1,n)
    {
        REP(j,1,m)
        {
            if(aa[i-1]==bb[j-1])
            {
                L[i][j] = L[i-1][j-1] + 1;
                lcss[i][j]=Up_Left;
            }
            else if(L[i-1][j]>= L[i][j-1])
            {
                L[i][j]=L[i-1][j];
                lcss[i][j] = UP;
            }
            else
            {
                L[i][j]=L[i][j-1];
                lcss[i][j]=LEFT;
            }
        }
    }

}

void generate_lcs(int i,int j)
{

    if(!i || !j)
        return;
    if(lcss[i][j]==Up_Left)
        {
            generate_lcs(i-1,j-1);
            lcs[p++]=aa[i-1];
      //      printf("%c",aa[i-1]);
        }
    else if(lcss[i][j]==UP)
        generate_lcs(i-1,j);
    else if(lcss[i][j]==LEFT)
        generate_lcs(i,j-1);

}


char ans[100000]; // store lcs
void lcs_length(char a[], char b[])
{
 int n;
 int m;
 n=strlen(a);
 m=strlen(b);
 int c[1000][1000];
 char v[1000][1000];
 for(int i=0;i<=n;i++)
 {
 c[i][0]=0;
 }
 for(int i=0;i<=m;i++)
 {
 c[0][i]=0;
 }
 for(int i=1;i<=n;i++)
 {
 for(int j=1;j<=m;j++)
 {
 if(a[i-1]==b[j-1])
 {
 c[i][j]=c[i-1][j-1]+1;
 v[i][j]='`';
 }
 else
 {
 if(c[i-1][j]>=c[i][j-1])
 {
 c[i][j]=c[i-1][j];
 v[i][j]='|';
 }
 else
 {
 c[i][j]=c[i][j-1];
 v[i][j]='-';
 }
 }
 }
 }
 int i=n,j=m;
 int k=0;
 while (1)
 {
 if(i==0 || j==0)
 {
 break;
 }
 else if(v[i][j]=='`')
 {
 i=i-1;
 j=j-1;
 ans[k++]=a[i];
 }
 else if(v[i][j]=='|')
 {
 i=i-1;
 j=j;
 }
 else if(v[i][j]=='-')
 {
 i=i;
 j=j-1;
 }

 }

 int l=0;
 int p=0;
 char store[10000]; // stores the output string
 i=n-1;
 j=m-1;
 while(j>=0 || i>=0)
 {
 if(l<k)
 {
 while(j>=0 && b[j]!=ans[l])
 {
 store[p++]=b[j];
 j--;
 }
 while(i>=0 && a[i]!=ans[l])
 {
 store[p++]=a[i];
 i--;
 }
 store[p++]=ans[l];
 l++;
 i--;
 j--;
 }
 else
 {
 while(j>=0)
 {
 store[p++]=b[j];
 j--;
 }
 while(i>=0)
 {
 store[p++]=a[i];
 i--;
 }
 }
 }
 for(int i=p-1;i>=0;i--)
 {
 printf("%c",store[i]);
 }
 printf("\n");
}

int main()
{
    inputfile();

    while(scanf("%s %s",aa,bb)==2)
    {
        lcs_length(aa,bb);

    }
    return 0;
}
