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
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
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

struct mystruct
{
  bool operator()(pair<int,char> const &a, pair<int,char> const &b) {
    return a.first > b.first;
  }
};



template <typename T1, typename T2>
struct less_second {
  typedef pair<T1, T2> type;
  bool operator ()(type const& a, type const& b) const {
    return a.second < b.second;
  }
};

pair<int,int> sad(pair<int,int> &a) {
  return a;
}



struct dsd
{
  int x;
  bool operator < (const dsd &a) {
    return this->x > a.x;
  }
};


int main(int argc, char const *argv[]) {
  BOOST;
  tuple<int,int,int> t;

  
  pair<int,int> ads;

  sad(ads);
  
  map<int, char> mm;

  std::vector< pair<int,char> > v(mm.begin(), mm.end());
  sort(v.begin(), v.end(), mystruct() );


  map<string, int> mymap;

  vector<pair<string, int> > mapcopy(mymap.begin(), mymap.end());
  sort(mapcopy.begin(), mapcopy.end(), less_second<string, int>());



  return 0;
}