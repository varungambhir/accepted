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

typedef pair<int,int> pii;

set<pii> s;

int main(int argc, char const *argv[])
{
  BOOST;
  int n,k,b,g,a;
  cin>>n;
  FOR(i,0,n)
  {
    cin>>k>>b;

    if(k==0)
      continue;
    g = __gcd(k,b);

    k = k/g;
    b = b/g;

    s.insert(pii(b,k));
  }

  cout<<s.size()<<endl;
  
  return 0;
}