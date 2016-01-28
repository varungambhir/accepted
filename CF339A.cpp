#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
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


int main(int argc, char const *argv[])
{
  ll l,r,k;
  while(cin >> l >> r >> k)
  {
    ll n = 1;
    ll prev = 0;
    bool check = 1;
    bool no_error = 0;

    while(n <= r && check)
    {
      if(n >= l)
        no_error = true , cout << n << " ";

      prev = n;
      n *= k;

      if( prev >= n || n%k != 0)
        check = false;
    }
    if(no_error == false)
    {
      cout << "-1";
    }
    cout << endl;

  }
  return 0;
}



/*
ll powr[MAXN];
ll a[MAXN];
ll temp[MAXN];
int main(int argc, char const *argv[])
{
  BOOST;
  int t;cin >> t;
  powr[0] = 1;
  FOR(i,1,MAXN)
    powr[i] = (powr[i-1]<<1)%MOD;
  while(t--)
  {
    ll n ;
    cin >> n;
    FOR(i,0,n+1)
    {
      cin >> a[i];
    }
    temp[0] = a[0] + a[0];
    FOR(i,1,n+1)
    {
      
    }
  }
  return 0;
}*/