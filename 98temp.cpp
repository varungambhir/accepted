#include <bits/stdc++.h>
typedef long long ll;
#define get(a) scanf("%lld", &a)
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
 
ll A[100005] = {0};
ll LA[100005] = {0};
ll RA[100005] = {0};
ll B[100005] = {0};
ll LB[100005] = {0};
ll RB[100005] = {0};
 
ll inA[100005] = {0};
ll outA[100005] = {0};
ll inB[100005] = {0};
ll outB[100005] = {0};
 
 
ll MOD = (ll)(1e9)+7;
 
map< ll,set<ll> > mapA, mapB; 
 
int main() {
    BOOST;
    ll n; cin >> n;
    
    FOR(i,1,n) {
        cin >> A[i];
        A[i] += i;
        mapA[ A[i] ].insert(i);
    }
    FOR(i,1,n) {
        cin >> B[i];
        B[i] += i;
        mapB[ B[i] ].insert(i);
    }
 
    vector<ll> v;
    
    FOR(i,1,n) {
        while( !v.empty() && A[v.back()] < A[i] ) {
            RA[v.back()] = i-1;
             v.pop_back();
        }
        v.pb(i);
    }
    
    while(!v.empty()) {
        RA[v.back()] = n;
        v.pop_back();
    }
 
    ROF(i,n,1) {
        while( !v.empty() && A[v.back()] <= A[i] ) {
            LA[v.back()] = i+1;
            v.pop_back();
        }
        v.pb(i);
    }
 
    while(!v.empty()) {
        LA[v.back()] = 1;
        v.pop_back();
    }
 
    FOR(i,1,n) {
        while( !v.empty() && B[v.back()] < B[i] ) {
            RB[v.back()] = i-1;
            v.pop_back();
        }
        v.pb(i);
    }
    
    while(!v.empty()) {
        RB[v.back()] = n;
        v.pop_back();
    }
 
    ROF(i,n,1) {
        while( !v.empty() && B[v.back()] <= B[i] ) {
            LB[v.back()] = i+1;
            v.pop_back();
        }
        v.pb(i);
    }
 
    while(!v.empty()) {
        LB[v.back()] = 1;
        v.pop_back();
    }
 
    set< pair< ll, pair<ll,ll> > > setA, setB;
        
    FOR(i,1,n) {
        cerr << "P: " << A[i] << ' ' << LA[i] << ' ' << RA[i] << '\n';
        if( setA.count( { A[i], { LA[i], RA[i] } } ) ) continue;
        setA.insert( { A[i], { LA[i], RA[i] } } );
        ll l = 1, r = RA[i] - LA[i] + 1, pos = i - LA[i] + 1;
        ll span = min( r-pos, pos-l );
        inA[l] += A[i];
        cerr << "l : " << l << " inA[l] " << inA[l] << "\n";
        inA[l+span+1] += -A[i];
        inA[r-span+1] += -A[i];
        inA[r+2] += A[i];
        cerr << "r+2: " << r+2 << " inA[r+2] " << inA[r+2] << "\n";
    }
    
    FOR(i,1,n) {
        if( setB.count( { B[i], { LB[i], RB[i] } } ) ) continue;
        setB.insert( { B[i], { LB[i], RB[i] } } );
        ll l = 1, r = RB[i] - LB[i] + 1, pos = i - LB[i] + 1;
        ll span = min( r-pos, pos-l );
        inB[l] += B[i];

        inB[l+span+1] += -B[i];
        inB[r-span+1] += -B[i];
        inB[r+2] += B[i];
    }
    
    ll sumA = 0, sumB = 0, addA = 0, addB = 0;
    FOR(i,1,n) {
        addA += inA[i];
        sumA += addA;
        
        addB += inB[i];
        sumB += addB;
        
        cerr << "\nU: " << inA[i] << ' ' << inB[i] << '\n';
        cerr << "\nR: " << sumA << ' ' << sumB << '\n';
        
        cout << (sumA%MOD)*(sumB%MOD) % MOD << ' ';
    }
}