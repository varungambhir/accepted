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

int a[20] = {0};

//http://codeforces.com/problemset/problem/349/B


int main(int argc, char const *argv[])
{
  BOOST;
  int v;
  cin >> v;
  int mini = INT_MAX;
  int id;
  FOR(i,1,9) {
    cin >> a[i];
    if(a[i] <= mini) {
      mini = a[i];
      id = i;
    }
  }

  int n = v/mini;

  if(n < 1) {
    cout << -1 << endl;
    return 0;
  }

  int drem = v - (v/mini)*mini;

  vector<pair<int,int> > x;

  for(int i = 9 ; i > id ; i--) {
    if(drem <= 0) break;

    int k = drem / (a[i] - mini);
    if(k > 0) {
      x.push_back(make_pair(i,k));
      drem -= k*(-mini +a[i]);
    }
  }

  for( pair<int,int> &j: x) {
    n -= j.second;
    FOR(i,1,j.second)
      cout << j.first;
  }

  FOR(i,1,n) {
    cout << id;
  }

  cout << endl;
  return 0;
}