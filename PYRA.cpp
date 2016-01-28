#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long  long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
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
#define F first
#define S second
#define PI acos(-1.0)
#define EPS 1e-9
#define Lf 2*r
#define Rg 2*r+1
#define M(x,i) memset(x,i,sizeof(x))
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define matrix vector< vector<ll> >

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
#define MAX 10003
#define mod 1000000007

vector<ll> Graph[MAX];
int visited[MAX];
ll vol[MAX];

ll dfs(ll node)
{
    visited[node] = 1;
    if(Graph[node].empty())
    {
        vol[node]=1;
        return 1;
    }
    FOR(i,0,Graph[node].size())
    {
        if(visited[Graph[node][i]]==0)
        {
            vol[node]= vol[node]+ 1 + dfs(Graph[node][i]);
        }
    }
    vol[node]++;

    return vol[node];

}

int main(int argc, char const *argv[])
{
    inputfile();cpp_input();
    int t,i,n,x1,x2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        FOR(i,0,n+1)
        {
        Graph[i].clear();
        visited[i]=vol[i]=0;
        }
        FF(i,1,n)
        {
            cin>>x1>>x2;
            Graph[x1].push_back(x2);
            Graph[x2].push_back(x1);
        }
        dfs(0);
        ll ans =0;
        FOR(i,0,n)
        {
            //debug(vol[i]);
            ans+=vol[i];
        }
        cout<<ans<<"\n";


    }
    return 0;
}
