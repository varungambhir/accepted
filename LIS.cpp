#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long  long int
#define pb push_back
#define FOR(i,a,n) for(int (i)=(a);(i) < (n); ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define FF(i,a,n) for ((i) = (a); (i)<(n);++(i))
#define REP(i,a,n) for ((i) = (a); (i)<=(n);++(i))
#define Sd(x) scanf("%d",&x)
#define all(c) c.begin(),c.end()
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
//#define F first
//#define S second
#define PI acos(-1.0)
#define EPS 1e-9
#define Lf 2*r
#define Rg 2*r+1
#define abs(x) ((x)<0 ? -(x) : (x))
#define M(x,i) memset(x,i,sizeof(x))//fill
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define matrix vector< vector<ll> >
//vector< vector<int> >Matrix(N, vector<int>(M,0));
inline void cpp_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
/*
#define gc getchar_unlocked
template <typename T>
void scanint(T &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
        if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
        if(neg) x=-x;
}*/

#define MAX 10005
#define MOD 1000000007

    int dp[5002];
    ll type[5002];

    int lis(int n)
    {

        fill(dp,dp+n,1);

        for(int i = 1; i<n;i++)
        {
           for(int j=0;j<i;j++)
           {
            if( (type[i] >= type[j]) && (dp[i] < (dp[j] +1)) )
            {
                dp[i] = dp[j] +1;
            }
        }
    }

/*FOR(i,0,n)
{
    debug(dp[i]);
}*/

    return *std::max_element(dp,dp+n);
}

int main(int argc, char const *argv[])
{
    cpp_input();
    int s,n,m,t;
    double temp;
    cin>>n>>m;
    FOR(i,0,n)
    {
        cin>>type[i]>>temp;
    }

    cout<< (n - lis(n))<<"\n";

    return 0;
}
