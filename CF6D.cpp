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

int h[MAXN] , path[MAXN];
int sol[MAXN];
int a,b,n,ans; 
int k = 0;
void decrease(int &x , int &y, int &z)
{
  x-=b; x = max(x,0);
  z-=b;  z = max(z,0);
  y-=a; y = max(y,0);
  return;
}

void dfs(int current,int Left,int mid,int right,int anss)
{
  if(anss>=ans)
    return;
  if(current==n)//last one
  {
    if(Left+mid+right == 0)
    {
      if(anss < ans)
      {
        ans = anss;
        FOR(i,0,anss)
        {
          sol[i] = path[i];
        }
      }
    }

    return ;
  }

  while(Left)
  {
    decrease(Left,mid,right);
    //debug(anss);
    path[anss++] = current;//index;
    //debug(anss);
  }
  //debug(Left); debug(mid);debug(right);

  //saare Left khatam kar do
  dfs(current+1 ,mid,right, h[current+2] , anss);
  //ab sirf right bach jayenge
  while(mid + right)
  {
    decrease(Left,mid,right);
    path[anss++] = current;
    //debug(mid);
    //debug(right);
    //debug(anss);
  dfs(current+1 , mid, right, h[current+2],anss);
  }
  //dfs(current+1 , mid, right, h[current+2],anss);
  
  return;
}

int main(int argc, char const *argv[])
{
  BOOST;
  //freopen("output.in","w",stdout);
  cin>>n>>a>>b;
  FOR(i,1,n+1)
  {
    cin>>h[i];
    h[i]++;
  }
  ans = 9876543;
  dfs(2,h[1],h[2],h[3],0);

  FOR(i,1,n+1)
  {
    cout<<h[i]<<" ";
  }
  cout<<"\n-------\n";
  cout<<ans<<endl;
  FOR(i,0,ans)
  {
    cout<<sol[i]<<" ";
  }
  cout<<"\n";

  return 0;
}