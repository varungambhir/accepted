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

int main(int argc, char const *argv[])
{
  BOOST;
  int n,h;
  std::vector<int> v,srt;
  cin>>n>>h;
  FOR(i,0,n)
  {
    int x;
    cin>>x;
    v.pb(x); srt.pb(x);
  }

  sort(srt.begin(), srt.end());

  int minsum = INT_MAX , maxsum =INT_MIN;
  int hmax = srt[n-1] + srt[n-2];
  int hmin = srt[0] + srt[1];

  if(srt.size()>2)
  {
    minsum = srt[1] + srt[2];
    maxsum = hmax;
  }

  FOR(i,1,n)
  {
    minsum = min(minsum, srt[0] + srt[i] + h);
    maxsum = max(maxsum, srt[0] + srt[i] + h);
  }

  bool flag = 0;//hmax - hmin smaller

  cout<<std::min(abs(hmax -hmin),abs(maxsum -minsum))<<endl;

  if( hmax-hmin > maxsum-minsum)
    flag = 1;

  FOR(i,0,n)
  {
    if(flag && v[i]==srt[0])
      {
        cout<<"1 ";
        flag = !flag;
      }
    else
      cout<<"2 ";
  }
  cout<<endl;
  return 0;
}