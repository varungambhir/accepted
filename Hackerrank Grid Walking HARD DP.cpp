#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
#define TRACE
#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif

const ll mod = (ll)1e9 + 7;

int main()
{
    int **binom = new int*[301];

    FOR(i,0,300)
    binom[i] = new int[301];

    FOR(i,1,300)
    binom[i][0] = binom[i][i] = 1;

    FOR(i,2,300)
    {
        FOR(j,1,i-1)
        {
            ll x  = ((ll)binom[i-1][j] + (ll)binom[i-1][j-1])%mod;
            binom[i][j] = x;
        }
    }

    int ***num_ways = new int **[101];
    
    FOR(i,0,100)
    num_ways[i] = new int*[101];

    FOR(i,0,100)
        FOR(j,0,100)
            num_ways[i][j] = new int[301];

    num_ways[1][1][0] = 1;
    FOR(i,1,100)
    num_ways[1][1][i] = 0;

    FOR(i,2,100)
    {
        FOR(j,1,100)
        num_ways[i][j][0] = 1;

        FOR(k,1,300)
        {
            FOR(j,1,i)
            {
                if(j == 1)
                {
                    num_ways[i][j][k] = num_ways[i][j+1][k-1];
                }
                else if(j == i)
                {
                    num_ways[i][j][k] = num_ways[i][j-1][k-1];
                }
                else
                {
                    num_ways[i][j][k] = ((ll)num_ways[i][j-1][k-1] + (ll)num_ways[i][j+1][k-1] )%mod;
                }
            }
        }

    }

    int t;
    cin >> t;
    while(t--)
    {
        int N, M;

        cin >> N >> M;

        int *a = new int[N];
        int *b = new int[M];

        FOR(i,0,N-1)
        cin >> a[i];

        FOR(i,0,N-1)
        cin >> b[i];

        int **P = new int*[N];

        FOR(i,0,N-1)
        P[i] = new int[M+1];

        FOR(i,0,M)
        {
            P[0][i] = num_ways[b[0]][a[0]][i];
        }
        //k steps in first dimension
        FOR(i,1,N-1) // dim
        {
            P[i][0] = 1;
            FOR(j,1,M)
            {
                ll s = 0;
                FOR(k,0,j)
                {
                    ll x = ((ll)binom[j][k] * (ll)num_ways[b[i]][a[i]][k] )%mod;
                    ll y = (x * (ll)P[i-1][j-k])%mod;
                    s = (s + y)%mod;
                }

                P[i][j] = s;
            }
        }

        cout << P[N-1][M] << endl;

        delete[] a;
        delete[] b;
        delete[] P;
    }
    return 0;
}