#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),c.end(),x) != (c).end())
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
  template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
  template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
  #define trace(...)
#endif

ll MOD = 1000000007LL;


int a[11000];

//http://codeforces.com/problemset/problem/289/B
// CF 177 Div 2 B

int main(int argc, char const *argv[])
{
  BOOST;
  int n,m,d;
  cin >> n >> m >> d;
  
  int min_ele = INT_MAX;
  
  FOR(i,0,n-1) {
    FOR(j,0,m-1) {
        cin >> a[i*m+j];
    }
  }

  sort(a,a+n*m);

  int index_median = (n*m+1)/2 -1;

  int index_median2 = (n*m+1)/2;

  int sum = 0;
  int sum2 = 0;
  int f = 0;

  FOR(i,0,n*m-1) {
    int diff = abs(a[i] - a[index_median]);
    if(diff % d != 0) {
        f = 1; break;
    }
    sum +=  diff/d;

    diff = abs(a[i] - a[index_median2]);

    sum2 += diff/d;
  }

  if(f) cout << -1 << endl;
  else if ((n*m) & 1) {
    cout << sum << endl;
  } else 
  cout << min(sum,sum2) << endl;

  return 0;
}