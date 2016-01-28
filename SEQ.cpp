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
#define matrix vector< vector< ll > >

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

vector< vector<ll> > s0;
int n,K,N,B[11] , C[11];

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
                c[i][j] = (c[i][j] + (a[i][p]*b[p][j])%mod)%mod;
        }
    }
}
void copy_matrix(matrix &a, matrix &b)
{
    FOR(i,0,a.size())
        FOR(j,0,a[0].size())
        a[i][j] = b[i][j];
}

ll fibo(int N)
{
    if(N<=K)
        return B[N-1];
    n = K;
    N = N - K;
    vector< vector< long long int > > a ,b ,c;
    a.resize(n);b.resize(n);c.resize(n);
    FOR(i,0,n)
    {
        a[i].resize(n);b[i].resize(n);c[i].resize(n);
    }
    FOR(i,0,K)
        a[0][i] = C[i];
    FOR(i,1,K)
        a[i][i-1] = 1;

        FOR(i,0,K)
        c[i][i]=1;

    while(N)
    {
        if(N%2==1)
        {
            multiply_matrix(c,a,b,n,n,n);
            copy_matrix(c,b);
        }
            multiply_matrix(a,a,b,n,n,n);
            copy_matrix(a,b);
            N = N>>1;

    }

    multiply_matrix(c,s0,b,n,n,1);

    if(b[0][0]<0)
    {
        b[0][0] += mod;
    }



    //matrix copycat(a);
    //cout<<"Yipee\n";
    //print_matrix(a);
    //print_matrix(copycat);
return b[0][0];
}

int main()
{
    inputfile();cpp_input();
    int t;
    cin>>t;
    while(t--)
    {
        cin>>K;

        FOR(i,0,K)
            cin>>B[i];

        FOR(i,0,K)
            cin>>C[i];

        cin>>N;
        n=K;
        s0.resize(n);
        FOR(i,0,n)
        {
            s0[i].resize(1);
        }
        FOR(i,0,K)
            s0[i][0] = B[K-i-1];

        ll ans = fibo(N)%mod;

        if(ans<0) ans = ans + mod;

        cout<<ans<<"\n";

    }
    return 0;
}
