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

int mat[1010][1010]={0};
int visit[1010][1010];//visit for '.' , seen for '*'
int ans;
int n,m;

int check(int x,int y)
{
    if( x<1 || x>n || y<1 || y>m || mat[x][y]!=0 || visit[x][y])
        return 0;
    return 1;
}
void dfs(int x,int y)
{

    //cout<<"X : "<< x << " Y : "<< y <<endl;
    visit[x][y] = 1;

    if(mat[x-1][y] && !visit[x-1][y])
    {
       // visit[x-1][y] = 1;
        ans++;
    } 
    if(mat[x][y-1] && !visit[x][y-1])
    {
       // visit[x][y-1] = 1;
        ans++;
    } 
    if(mat[x+1][y] && !visit[x+1][y])
    {
        //visit[x+1][y] = 1;
        ans++;
    } 
    if(mat[x][y+1] && !visit[x][y+1])
    {
        //visit[x][y+1] = 1;
        ans++;
    } 

    if( check(x-1,y) )
    {
        dfs(x-1,y);
    }

    if( check(x+1,y) )
    {
        dfs(x+1,y);
    }
    
    if( check(x,y+1) )
    {
        dfs(x,y+1);
    }

    if( check(x,y-1) )
    {
        dfs(x,y-1);
    }

    return;

}

int main(int argc, char const *argv[])
{
    BOOST;
    char c;
    int k;
    cin>>n>>m>>k;
    FOR(i,1,n+1)
    {

        FOR(j,1,m+1)
        {
            cin>>c;
            if(c=='.')
            {
                mat[i][j] = 0;
            }
            else//'*'
            {
                mat[i][j] = 1;
            }
        }
    }

    while(k--)
    {
        int x,y;
        memset(visit,0,sizeof(visit));
        cin>>x>>y;
        ans = 0;
        if(mat[x][y])
            ans = 0;
        else
        {
            dfs(x,y);
        }

        cout<<ans<<endl;

    }
    return 0;
}