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

int cnt[2][300000];
int main(int argc, char const *argv[])
{
  //INPFILE;
  string s;
  string t;
  while(cin >> s >> t)
  {
    int len = t.length();
    int slen = s.length();
    s = " " + s;
    t = " " + t;

    memset(cnt,0,sizeof(cnt));
    FOR(i,1,len+1)
    {
      cnt[1][i] = cnt[1][i-1];
      cnt[0][i] = cnt[0][i-1];

      cnt[ t[i] - '0' ][i]++;
    }
    ll ans = 0;
    FOR(i,1,slen+1)
    {
      int from = i;
      int to = i + len - slen;
      
      if( from > to)
        continue;

      int ot = 1 - (s[i] -'0');
      ans += cnt[ot][to] - cnt[ot][from-1];
    }


    cout << ans << endl;

  }


  return 0;
}
