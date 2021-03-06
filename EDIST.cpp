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

int dp[2020];

int editDist(string &s1,char *s2,int n)
{
    //memset(dp,0,sizeof(dp));
    int cnt = 0;
    FOR(i,0,n)
    {
        if(s1[i]!=s2[i])
            cnt++;
    }

    return cnt;
}
char s2[2020];
int main(int argc, char const *argv[])
{
    BOOST;
    int t;
    //cin>>t;
    string s1,s3;
    while(cin>>s1)
    {
        FOR(i,0,s1.length())
        {
            if(i&1)
            s2[i] = toupper(s1[i]);
            else
            s2[i] = tolower(s1[i]); 
        }
        s2[s1.length()] = '\0';

        t = editDist(s1,s2,s1.size());

        FOR(i,0,s1.length())
        {
            if(i&1)
            s2[i] = tolower(s1[i]);
            else
            s2[i] = toupper(s1[i]); 
        }
        s2[s1.length()] = '\0';

        t = std::min(t,editDist(s1,s2,s1.size() ) );
        
        cout<<t<<"\n";
    }
    return 0;
}