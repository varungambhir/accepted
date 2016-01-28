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
#define MAXN 100005
#define MOD 1000000007

double dp[1000][1000];
int n;
std::vector<int> v;
double rec(int ind , int count)
{
    cout<<ind<<" "<<count<<endl;
    if(ind==n)
        return count;
    if(dp[ind][count]!=-1)
        return dp[ind][count];

    if(v[ind]==-1)
    {
        dp[ind][count] = 0.5*rec(ind+1,count+1) + 0.5*rec(ind+1,count);
        cout<<"ind " << ind << " count "<< count <<" dp[ind][count] "<<dp[ind][count]<< endl;
        return dp[ind][count];
    }
    else
    {
        dp[ind][count] = rec(ind+1,count);
        cout<<"ind " << ind << " count "<< count <<" dp[ind][count "<<dp[ind][count]<< endl;
        return dp[ind][count];
    }
}

int main(int argc, char const *argv[])
{
    
    v.clear();
    int x;
    cin>>n;
    FOR(i,0,n)
    {
        cin>>x;
        v.pb(x);
    }
    FOR(i,0,1000)
    {
        FOR(j,0,1000)
        {
            dp[i][j] = -1.0;
        }
    }
    int ans = rec(1,1);
    cout<<ans<<endl;
    return 0;
}