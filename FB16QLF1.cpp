#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%lld",&x)
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

//unordered_map<ll, vector<pair < pair<ll,ll> , pair<ll,ll> > > > m; 

unordered_map<ll, ll > m; 
vector<pair<ll,ll> > a;
int main(int argc, char const *argv[])
{
 // std::clock_t c_start = std::clock();
  //auto t_start = std::chrono::high_resolution_clock::now();

  int t;//=50;
  scanf("%d",&t);
  FOR(c,1,t+1)
  {  
    a.clear();
    ll n,d;
    SD(n);
    FOR(i,1,n+1)
    {
      ll x,y;
      SD(x);SD(y);
      a.push_back( make_pair(x,y) );
    }
    if( n < 3)
    {
      cout << "Case #" << c << ": 0\n";
      continue;
    }
    ll cnt = 0;
    FOR(i,0,n)
    {
      m.clear();
      FOR(j,0,n)
      {
        if(i == j)
          continue;
        d = (a[i].F - a[j].F)*(a[i].F - a[j].F) + (a[i].S - a[j].S)*(a[i].S - a[j].S);
        m[d]++;
      }

      for(auto &it : m)
        cnt += ((it.second)*(it.second -1))/2;
    }

    printf("Case #%d: %lld\n",c,cnt);

  }
  /*std::clock_t c_end = std::clock();
  auto t_end = std::chrono::high_resolution_clock::now();

  cout << "Wall clock time passed: "
  << std::chrono::duration<double, std::milli>(t_end-t_start).count()
  << " ms\n";
  */
  return 0;
}
