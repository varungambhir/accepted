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
ll table[14];
ll a[MAXN],b[MAXN];
void func()
{
  table[0]=1;
  FOR(i,1,14)
  table[i] = table[i-1]*10;
}

int main(int argc, char const *argv[])
{
  BOOST;
  func();
  int n,k;
  while(cin >> n >> k)
  { 
  FOR(i,0,n/k)
  {
    cin>>a[i];
    b[i] = 0;
  }
  int x;
  FOR(i,0,n/k)
  {
    cin >> x;
    ll temp = (table[k]-1)/a[i];
    if(x!=0)
    {
      ll t1 = x;
      ll t2 = x-1;
      /*FOR(j,0,k-1)
      {
        t1 = t1*10+9;
        t2 = t2*10+9;
      }*/
      t1 = t1*table[k-1];
      t2 = t2*table[k-1];
        t1 += table[k-1]-1;
        t2 += table[k-1]-1;
     // debug(t1);
    //  debug(t2);
      b[i] = temp - (t1)/a[i] + (t2)/a[i] +1;
    }
    else
    {
      b[i] = temp - (table[k-1]-1)/a[i];
    }
  }

  ll ans = 1;
  FOR(i,0,n/k)
  {
    ans = (ans*b[i])%MOD;
  }
  cout << ans << endl;
}
  return 0;
}