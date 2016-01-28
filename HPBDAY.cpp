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
#define repstl(v) for(typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
#define MAXN 1010
#define MOD 1000000007
 
 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/

bool sumofdig(ll n)
{
  ll r;
  ll sum = 0;
  while(n>0)
  {
    r = n%10;
    sum += r;
    n /= 10;
  }

  if(sum == 13)
    return true;
  else
    return false;

}

std::vector<int> v{6, 75, 480, 2205, 8232, 26544, 76500};

int main(int argc, char const *argv[])
{
  BOOST;
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin >> n;
    FOR(i,0,v.size())
    {
      if( n <= v[i])
      {
        cout << i+2 << endl;
        break; 
      }
    }
  }
  
  return 0;
}

