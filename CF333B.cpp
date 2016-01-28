#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
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
#define MAXN 1010
#define MOD 1000000007
int a[(int)1e6];
int dp[(int)1e6][2];

int main(int argc, char const *argv[])
{
    BOOST;
    int n;
    cin>>n;
    FOR(i,0,n)
    {
        cin>>a[i];
        dp[i][0] = dp[i][1] = 1;
        //all a's < = i ending i , >= i ending i 
    }

    FOR(i,1,n)
    {
        if(a[i] == a[i-1])
        {
            dp[i][0] += dp[i-1][0];
            dp[i][1] += dp[i-1][1];
        }
        else if (a[i] > a[i-1])
        {
            dp[i][0] += dp[i-1][1]; 
        }
        else if (a[i] < a[i-1])
        {
            dp[i][1] += dp[i-1][0];
        }
    }
    int maxi = -1;
    FOR(i,0,n)
    {
        FOR(j,0,2)
        {
            maxi = max(maxi,dp[i][j]);
        }
    }
    cout<<maxi<<endl;
    return 0;
}