#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define F first
#define S second
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define MAX 500010
#define MOD 1000000007
#define endl "\n"
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef pair<int,int> pii;

int dp[200010][550];
int main() 
{
    char s[200010];
    scanf("%s",s);
    int len = strlen(s);
    int m,l,q;
    SD(q);
    while(q--)
    {
        cin>>m>>l;
        int count = 0;

        memset(dp,0,sizeof(dp));
        FOR(i,1,len+1)
        {
            FOR(j,0,m)
            {
                dp[i][(j*10 + (s[i-1]-'0'))%m] += dp[i-1][j];
            }

            dp[i][(s[i-1]-'0')%m]++;

            count = count + dp[i][l];
        }
        printf("%d\n", count);
    }
    return 0;
}
