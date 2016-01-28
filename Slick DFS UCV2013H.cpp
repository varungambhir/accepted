#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define Sd(x) scanf("%d",&x)
#define f first
#define s second
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define MAX 1000005
#define MOD 1000000007
#define endl "\n"
typedef pair<int,int> pii;

#define MAXX 252
int arr[MAXX][MAXX], traversed[MAXX][MAXX], splic[MAXX][MAXX];
int sizess[MAXX*MAXX] , splic_total[MAXX*MAXX];

void dfs(int i,int j, int n,int m, int splic_no)
{
    if(arr[i][j]!=0)
    {
        sizess[splic_no]++;
        splic[i][j] = splic_no;
        traversed[i][j] = 1;

        if(i>0 && !traversed[i-1][j])
            dfs(i-1,j,n,m,splic_no);
        
        if(i<(n-1) && !traversed[i+1][j])
            dfs(i+1,j,n,m,splic_no);

        if(j>0&&!(traversed[i][j-1])) 
            dfs(i,j-1,n,m,splic_no);

        if(j<m-1&&!(traversed[i][j+1])) 
            dfs(i,j+1,n,m,splic_no);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //freopen("input.in","r",stdin);
    int n,m;
    while(true)
    {
        cin>>n>>m;
        if(!n && !m) break;
        FOR(i,0,n)
        FOR(j,0,m)
        {
            cin>>arr[i][j];
            traversed[i][j]=0;
            splic[i][j]=-1;
        }
        memset(sizess,0,sizeof(sizess));
        int no = 0;
        FOR(i,0,n)
        {
            FOR(j,0,m)
            {
                if(arr[i][j]==1 && !traversed[i][j])
                {
                    dfs(i,j,n,m,no++);
                }
            }
        }

        cout<<no<<endl;
        memset(splic_total,0,sizeof(splic_total));
        FOR(i,0,no)
        {
            splic_total[sizess[i]]++;
        }
        int c =0;
        FOR(i,0,MAXX*MAXX)
        {
            if(c>=no) break;
            if(splic_total[i]!=0)
            {
                cout<<i<<" "<<splic_total[i]<<endl;
            }
        }
    }
    return 0;
}
