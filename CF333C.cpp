#include <bits/stdc++.h>
typedef long long ll;
#define SD(a) scanf("%d", &a)
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

ll adj[405][405] = {0};
ll v[405][405] = {0};


ll mark[405] = {0};


int main() {
    ll n, m;
    cin >> n >> m;
    
    FOR(i,1,n)
     FOR(j,1,n)
      if( i != j ) 
       adj[i][j] = v[i][j] = INT_MAX;
       
    while(m--) {
        ll x, y;
        cin >> x >> y;
        adj[x][y] = adj[y][x] = 1;
    }
    
    FOR(i,1,n)
     FOR(j,1,n)
      if( adj[i][j] == INT_MAX )
        v[i][j] = 1;
    vector<ll> train, bus; 
    
    FOR(k,1,n)
     FOR(i,1,n)
      FOR(j,1,n) {
       adj[i][j] = min( adj[i][j], adj[i][k] + adj[k][j] );
       if( i == 1 && j == n && adj[i][j] < INT_MAX )
         train.pb( adj[i][j] );
      }

    
    FOR(k,1,n)
     FOR(i,1,n)
      FOR(j,1,n) {
       v[i][j] = min( v[i][j], v[i][k] + v[k][j] );
       if( i == 1 && j == n && v[i][j] < INT_MAX )
         bus.pb( v[i][j] );
      }
    
    if( train.empty() || bus.empty() )
       { cout << "-1"; return 0; }
    sort( all(train) );
    sort( all(bus) );
    
    cout << max( train[0], bus[0] );
    
return 0;
    
}