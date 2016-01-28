#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%lld",&x)
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
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
#define MAXN 100005
#define MOD 1000000007

ll C( ll n, ll k ) {
  if( k > n ) return 0;
  if( k == 0 || n == k )
    return 1;
  if( nCk[n][k] )
   return nCk[n][k];
  return nCk[n][k] = C(n-1,k-1) + C(n-1,k);
}

ll ncr(ll n , ll r )
{
    if(r > n/2)
        r = n-r;
    ll product = 1;

    ll i;

    for(i =  1; i<=r; i++)
    {
        product = product * (n-r+i);
        product = product/i; 
    }
    return product;
}

int main(int argc, char const *argv[])
{
  long long n , k;
  SD(k);
  for(ll i = 0; i < k; i++)
  {
    for(ll j = 0 ; j <=i ; j++)
    {
        if(j==i || !j)
            printf("1 " );
        else
        {
            printf("%lld ",ncr(i,j) );
        }

    }
    printf("\n");
  }
  
  
  return 0;
}