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
#define F first
#define S second
#define PI acos(-1.0)
#define EPS 1e-9
#define Lf 2*r
#define Rg 2*r+1
#define M(x,i) memset(x,i,sizeof(x))
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define matrix vector< vector<int> >
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
#define mod 1000000000

void print_matrix(matrix &a)
{
    FOR(i,0,a.size())
    {
        FOR(j,0,a[0].size())
            cout<<a[i][j]<<" ";

        cout<<"\n";
    }
}

void multiply_matrix(matrix &a, matrix &b, matrix &c , int m,int k,int n)
{
    FOR(i,0,m)
    {
        FOR(j,0,n)
        {
            c[i][j]=0;
            FOR(p,0,k)
                c[i][j] = c[i][j] + a[i][p]*b[p][j];
        }
    }
}
void copy_matrix(matrix &a, matrix &b)
{
    FOR(i,0,a.size())
        FOR(j,0,a[0].size())
        a[i][j] = b[i][j];
}


int main()
{
    inputfile();cpp_input();
    int n,e,m,a,w,b,t;
    cin>>n>>e>>t>>m;
    e--;
    vector< vector<int> > G(n, vector<int>(n,10000000));
    //print_matrix(G);
    FOR(i,0,m)
    {
        cin>>a>>b>>w;
        G[a-1][b-1] = w;
    }
    FOR(i,0,n)
    {
        G[i][i]=0;
    }
    FOR(k,0,n)
    {
        FOR(i,0,n)
        {
            FOR(j,0,n)
            {
                G[i][j] = min( G[i][j] , G[i][k] + G[k][j]);
            }
        }
    }
    //pr-int_matrix(G);
    int cnt= 0;
    FOR(i,0,n)
    {
        if(G[i][e]<=t)
            cnt++;
    }   

    cout<<cnt;

    return 0;
}
