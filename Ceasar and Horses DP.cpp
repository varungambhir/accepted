#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long  long int
#define pii pair<int,int>
#define mpp make_pair
#define pb push_back
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
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define F first
#define S second
#define PI acos(-1.0)
#define EPS 1e-9
#define Lf 2*r
#define Rg 2*r+1
#define M(x,i) memset(x,i,sizeof(x))
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define matrix vector< vector<ll> >
//vector< vector<int> >Matrix(N, vector<int>(M,0));
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
#define MAX 100003
#define MOD 100000000

ll n1,n2,k1,k2;
ll dp[110][110][11][11];

ll recur(ll x,ll y,ll soldier,ll horse)
{
    if(dp[x][y][soldier][horse] != -1)
        return dp[x][y][soldier][horse];

    if(y == n2 && x==n1)
        return dp[x][y][soldier][horse]=1;
    if(y>n2 || x>n1)
        return dp[x][y][soldier][horse]=0;
    if(soldier==k1)
        return dp[x][y][soldier][horse] = recur(x,y+1,0,1)%MOD;
    if(horse==k2)
        return dp[x][y][soldier][horse] = recur(x+1,y,1,0)%MOD;

    return dp[x][y][soldier][horse] = (recur(x+1,y,soldier+1,0) +  recur(x,y+1,0,horse+1)) %MOD;
}
int main() {

inputfile();cpp_input();
M(dp,-1);
cin>>n1>>n2>>k1>>k2;
cout<<recur(0,0,0,0)%MOD;

    return 0;
}
