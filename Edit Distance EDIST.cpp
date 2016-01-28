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
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define MAXN 10000005
#define MOD 1000000007

int dp[2020][2020];

int editDist(string &s1,string &s2,int n,int m)
{
    memset(dp,0,sizeof(dp));

    FOR(i,0,n+1)
    {
        FOR(j,0,m+1)
        {
            if(!i)
                dp[i][j] = j;
            
            else if(!j)
                dp[i][j] = i;

            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 0;
            else
            {
                dp[i][j] = std::min(1 + dp[i-1][j],//delete
                           std::min(1 + dp[i][j-1],//insert
                                    dp[i-1][j-1] + 1//replace
                                        )
                                    ); 
            }
        }
    }

    return dp[n][m];
}

int main(int argc, char const *argv[])
{
    BOOST;
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        cout<<editDist(s1,s2,s1.size(),s2.size())<<"\n";
    }
    return 0;
}