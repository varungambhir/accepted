#include <bits/stdc++.h>
typedef long long ll;
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = (ll)(a); i <= (ll)(b); i++ )
#define ROF(i,a,b) for( ll i = (ll)(a); i >= (ll)(b); i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/
ll arr[105] = {0};
ll size[105] = {0};
ll maxi[105][105] = {{0}};
ll dp[105][10005] = {{0}};
ll n, m;

ll rec( ll index, ll rem ) {
    if( index > n  && rem == 0 )
      return 0;
    if( index > n && rem != 0 )
      return LONG_MIN;
    
    if( dp[index][rem] != -1 )
     return dp[index][rem];
     
    ll val = 0;
    FOR(i,0,min(rem,size[index]))
     val = max( val, maxi[index][i] + rec( index+1, rem-i ) );
    
    return dp[index][rem] = val;
}

int main() {
    cin >> n >> m;
    
    FOR(i,1,n) {
        ll sz; cin >> sz;
        size[i] = sz;
        FOR(j,1,sz)
         cin >> arr[j];
        arr[0] = arr[sz+1] = 0;
        
        ll start = 0, end = 0;
        FOR(x,0,sz) {
          start += arr[x]; end = 0;
         ROF(y,sz+1,1) {
          end += arr[y];
          if( y <= x ) break;
           maxi[i][x+sz-y+1] = max( maxi[i][x+sz-y+1], start + end ); 
         }
        }
/*
    FOR(j,0,l)
    {
      front = sum2[i][j];
      ROF(k,l+1,1)
      {
        if( k <= j) break;
        if(k == l+1)
          back = 0;
        else
          back = sum2[i][l] - sum2[i][k-1];
        sum[i][l+1 -k +j] = max(sum[i][l+1-k+j] , front + back); 
      }
    }*/
        
    }
    
    memset( dp, -1, sizeof dp );
    cout << rec(1,m);
return 0;
    
}