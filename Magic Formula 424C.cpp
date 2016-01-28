#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long  long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define FOR(i,a,n) for(int (i)=(a);(i) < (n); ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define FF(i,a,n) for ((i) = (a); (i)<(n);++(i))
#define REP(i,a,n) for ((i) = (a); (i)<=(n);++(i))
#define V(x) vector<x>
#define Sd(x) scanf("%d",&x)
#define all(c) c.begin(),c.end()
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define F first
#define S second
#define PI acos(-1.0)
#define EPS 1e-9
#define Lf 2*r
#define Rg 2*r+1
#define M(x,i) memset(x,i,sizeof(x))
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define matrix vector< vector<ll> >

inline void inputfile()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	#endif
}
inline void cpp_input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
#define MAX 100010
#define mod 1000000007
ll n;
ll arr[100010];
ll fact[100010];
ll q,p;
int main()
{
  inputfile();
  cpp_input();
  cin>>n;// here fact means xor
  FOR(i,1,n)
  {
    fact[i] = (fact[i-1] ^ i);
  }
ll Q = 0;  
  FOR(i,1,n+1)
  {
    cin>>arr[i];
    Q = Q ^ arr[i];
  }

  FOR(i,1,n+1)
  {
    p = n/i;

    q = n%i;

    p = p%2;

    if(p)
      Q = Q ^ fact[i-1];
    Q = Q ^ fact[q];
  }

  cout<<Q<<"\n";

  return 0;
}
