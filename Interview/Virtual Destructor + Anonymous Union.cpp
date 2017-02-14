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


class a
{
public:
  a() {
    cout << "Init A\n";
  }
  virtual ~a() {
    cout << "Destroying A\n";
  }
};


class b : public a
{
public:
  b() {
    cout << "Init B\n";
  }
  ~b() {
    cout << "Destroying B\n";
  }
};

class c : public b
{
public:
  int x;
  int y;
  c(int d, int e) : x(d), y(e)  {
    cout << "Init C\n";
  }
  c(int d): x(d)  {
    cout << "Init 2 C\n";
    this->y = -10;
    cout << this->x << " " << this->y << endl;
  }
  ~c() {
    cout << "Destroying C\n";
  }
  friend int getsome(c d);
};

int getsome(c d) {
  int sum = d.x * d.y;
  return sum;
}


//virtual destructor declared in base class.
int main(int argc, char const *argv[]) {
  BOOST;
  a *ptr = new c; 
  delete ptr;

  // Anonymous Union
  union {
    ll l;
    double d;
    char s[4];
  };

  // now, reference union elements directly
  d = 123.2342;
  cout << d << " ";
  l = 100000;
  cout << l << " ";
  strcpy(s, "hi\0");
  cout << s << " ";
  cout << d << "\n";


  b *ptrr = new c;
  delete ptrr;

  return 0;
}