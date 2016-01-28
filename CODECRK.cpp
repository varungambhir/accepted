#include <bits/stdc++.h>
typedef long long ll;
//#define get(a) scanf("%ld", &a)
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
 
void brute( double a, double b ) {
  ll N = 10;
  double x = sqrt(2), y = sqrt(3);
  vector<double> A, B;
  
  FOR(i,2,N) {
    A.pb(a); B.pb(b);
    double p = x*( a + b ) - x*y*( a - b );
    double q = x*( a - b ) + x*y*( a + b );
    a = p; b = q;
  }
  
  for( double q : A )
   cout << q << " ";
  cout << "\n";
  for( double q : B )
   cout << q << " ";
  cout << "\n";
}
 
ll i, k, s;
double a, b;
 
double divf(double a,int times)
{ 
  double last = -1;
  while(times--)
  {
    if(abs(a - last) < 0.00001)
      return a;
    last = a;
    a /=2;
  }
  return a;
}
double solve() {
  double x = sqrt(2), y = sqrt(3);
  double a_p = ( -a*(x*y-x) + b*(x+x*y) )/(2*x*x*(1+y*y));
  double b_p = ( a*( x + x*y ) - b*( x - x*y ) )/(2*x*x*(1+y*y));
  
  
  ll p =0;
  if( i%2 == k%2)
    p = (k-i)/2;
  else
    p = (k-(i-1))/2;

  p = p*4;
  p = p-s;

  
  double ans = 0;
  if(i%2 == k%2) 
  {
    ans = a+b;
  }
  else
  {
    ans = a_p + b_p;
  }

  if(p<0)
    ans = divf(ans,-p);
  else
    ans = ans * pow(2,p);
  return ans;
}
 
int main() 
{
  cin >> i >> k >> s;
  cin >> a >> b;
  //brute(a,b)
  printf("%0.4lf\n",solve());
  return 0;  
}