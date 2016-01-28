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
multiset<int> f , r;
map<int,int> arr;
set<int> no;
multiset<int>::iterator it1,it2;
int main(int argc, char const *argv[])
{
 // BOOST;
  int x,y;
  int n;
  cin >> n;
  FOR(i,1,n+1)
  {
    cin >> x >> y;
    if( x != y)
    {
      //r.insert(y);
      arr[y]++;
    }
    f.insert(x);
    arr[x]++;

    if( arr[x] >= ceil(n*0.5) )
      no.insert(x);
    if ( arr[y] >= ceil(n*0.5)  && x!=y )
      no.insert(y);
  }
  /*repstl(no)
  {
    cerr << *it << " " << arr[*it] << endl;
  }*/

  if(no.empty()) {cout << "-1\n";return 0;}

  int ans = INT_MAX;
  
  repstl(no)
  {
    int x = *it;
    debug(*it);
    it1 = upper_bound(f.begin(),f.end(),x);
    it2 = lower_bound(f.begin(),f.end(),x) ;
    int cnt = distance(it2,it1);
    debug(cnt);
    if( ( (cnt >= n/2 && !(n&1)) || (cnt > n/2 && (n&1)) ) )
      { ans = min(0,ans); break; }
    ans = (n&1 == 1) ? min(ans,n/2-cnt+1) : min(ans,n/2-cnt);
  }

  cout << ans << endl;

  return 0;
}