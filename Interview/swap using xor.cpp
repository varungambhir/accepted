#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%lld",&x)
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
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif

 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/
#define MAXN 3000005
#define MOD 1000000007

void swap(int &x, int &y)
{
  x = x ^ y ;
  y = x ^ y ;
  x = x ^ y ;
}

/*
  // x == A, y == B
  x = x ^ y ;  
   // x == A ^ B, y == B
  y = x ^ y ;  
   // x == A ^ B
   // y == (A ^ B) ^ B == A ^ (B ^ B)  (by Assoc)
   //   == A ^ 0  (by z ^ z == 0 property)
   //   == A      (by z ^ 0 == z property)
  x = x ^ y ;
   // x == ( A ^ B ) ^ A
   //   == ( A ^ A ) ^ B  (by Assoc/Commutativity)
   //   == 0 ^ B            (by z ^ z == 0 property)
   //   == B                (by z ^ 0 == z property)
   // y == A
*/

ll a[1000100];

int main(int argc, char const *argv[])
{
    int aa = 7;
    int b = 3;
    int  c = 5;

    int ans = aa^(b+c);
    int as = b^c;
    cout << as <<endl;
    cout << ans << endl;  
    return 0;
}