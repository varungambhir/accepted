//https://www.hackerrank.com/contests/amazon/challenges/connected-sets
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L 2*node
#define R 2*node+1
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define MAXN 100005
#define MOD 1000000007

int arr[1100][1100]={0};
int visit[1100][1100]={0};
int cnt = 0;
int n;
bool check(int x,int y)
{
  if(x<1 || x>n || y<1 || y>n )
    return false;
  return true;
}

void dfs(int x,int y)
{
  visit[x][y] = 1;

  if(check(x+1,y) && arr[x+1][y]!=0 && !visit[x+1][y])
    dfs(x+1,y);
  
  if(check(x,y+1) && arr[x][y+1]!=0 && !visit[x][y+1])
    dfs(x,y+1);

  if(check(x+1,y+1) && arr[x+1][y+1]!=0 && !visit[x+1][y+1])
    dfs(x+1,y+1);

  if(check(x-1,y) && arr[x-1][y]!=0 && !visit[x-1][y])
    dfs(x-1,y);

  if(check(x-1,y-1) && arr[x-1][y-1]!=0 && !visit[x-1][y-1])
    dfs(x-1,y-1);

  if(check(x,y-1) && arr[x][y-1]!=0 && !visit[x][y-1])
    dfs(x,y-1);


  if(check(x+1,y-1) && arr[x+1][y-1]!=0 && !visit[x+1][y-1])
    dfs(x+1,y-1);
  
  if(check(x-1,y+1) && arr[x-1][y+1]!=0 && !visit[x-1][y+1])
    dfs(x-1,y+1);

  return;
}

int main(int argc, char const *argv[])
{
  BOOST;
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n;
    FOR(i,1,n+1)
    {
      FOR(j,1,n+1)
      {
        cin>>arr[i][j];
        visit[i][j] = 0;
      }
    }
    cnt = 0;
    FOR(i,1,n+1)
    {
      FOR(j,1,n+1)
      {
        if((arr[i][j]==1) && (visit[i][j]==0))
        {
          dfs(i,j);
      //    cout<<"i : "<< i << "j : "<<j<<endl; 
          cnt++;
        }
      }
    }
    //cout<<endl;
    cout<<cnt<<endl;
  }
  return 0;
}