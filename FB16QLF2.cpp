#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define SL(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L 2*node
#define R 2*node+1
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
#define MAXN 100010
#define MOD 1000000007
 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/

char s[2][1100];
int  a[2][1100];


void dfs(int i,int j)
{
  int k = j;
  while(a[i][k])
    a[i][k++] = 0;

  k = j-1;

  while(a[i][k])
    a[i][k--] = 0;
}

int main(int argc, char const *argv[])
{
  //inputfile();
  int t;
  SD(t);
  FOR(z,1,t+1)
  {
    int n;
    int cnt = 0;
    SD(n);
    scanf("%s",s[0]);
    scanf("%s",s[1]);
    memset(a,0,sizeof(a));
    FOR(i,0,n)
    {
      if(s[0][i] == '.')
        a[0][i+1] = 1;

      if(s[1][i] == '.')
        a[1][i+1] = 1;
    }
    FOR(i,0,2)
    {
      FOR(j,1,n+1)
      {
        if(a[i][j] && a[i^1][j] && !a[i][j-1] && !a[i][j+1])
          {
            a[i][j] = 0;
            dfs( (i^1),j );       
            cnt++;
          }
      }
    }
    FOR(i,0,2)
    {
      FOR(j,1,n+1)
      {
        if(a[i][j])
        {
          dfs(i,j);
          cnt++;
        }
      }
    }
    printf("Case #%d: %d\n",z,cnt);

  }
  return 0;
}