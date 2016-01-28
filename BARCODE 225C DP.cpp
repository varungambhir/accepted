#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long  long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define FOR(i,a,n) for(int (i)=(a);(i) < (n); ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define FF(i,a,n) for ((i) = (a); (i)<(n);++(i))
#define REP(i,a,n) for ((i) = (a); (i)<=(n);++(i))
#define V(x) vector<x>
#define Sd(x) scanf("%d",&x)
#define all(c) c.begin(),c.end()
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define F first
#define S second
#define PI acos(-1.0)
#define EPS 1e-9
#define Lf 2*r
#define Rg 2*r+1
#define M(x,i) memset(x,i,sizeof(x))
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define matrix vector< vector<ll> >

inline void inputfile()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	#endif
}
inline void cpp_input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
#define MAX 100010
#define mod 1000000007

int n,m,x,y,i,j,k;
int dp[1005][2],a[1005];
char b[1005][1005];

int main()
{
	inputfile();
	cpp_input();
	
  while(~scanf("%d%d%d%d",&n,&m,&x,&y))
   {
       memset(a,0,sizeof(a));
       memset(b,0,sizeof(b));
     for(i=0;i<n;i++)
      {
          scanf("%s",b[i]);
          for(j=0;j<m;j++)
            if(b[i][j]=='#')
               a[j+1]++;
        }

     for(i=1;i<m;i++)
        a[i+1]+=a[i];
    for(i=0;i<=m;i++)
     dp[i][0]=dp[i][1]=m*n;
    dp[0][1]=dp[0][0]=1;
    for(i=0;i<m;i++)
     {
         for(j=x;j<=y&&i+j<=m;j++)
           {
               dp[i+j][0]=min(dp[i+j][0],dp[i][1]+(a[i+j]-a[i]));
               dp[i+j][1]=min(dp[i+j][1],dp[i][0]+j*n-(a[i+j]-a[i]));
               //cout<<dp[i+j][0]<<"***"<<dp[i+j][1]<<" ";
           }
        //cout<<endl;
     }
    cout<<min(dp[m][0],dp[m][1])-1<<"\n";
   }
    return 0;
}