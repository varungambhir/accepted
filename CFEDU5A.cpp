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
int comp(string &a, string &b)
{
  int la = a.size(); int lb = b.size();
  while(la > 1 && a[a.size() - la] == '0') la--;
  while(lb > 1 && b[b.size() - lb] == '0') lb--;

  if(la > lb) return 1;
  if(la < lb) return -1;

  while(la > 1 && a[a.size() - la] == b[b.size() - lb])
  {
    la--;
    lb--;
  }

  if(a[a.size() - la] > b[b.size() - lb])
    return 1;
  else if(a[a.size() - la] < b[b.size() - lb])
    return -1;
  else
    return 0;
}

int main(int argc, char const *argv[])
{
  string a;
  string b;
  cin >> a >> b;

  int r = comp(a,b);
  if( r == -1)
    cout << "<";
  else if(r == 1)
    cout << ">";
  else
    cout << "=";
  return 0;
}