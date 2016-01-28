#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
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
#define MAX 200010
#define MOD 1000000007

typedef pair<int,int> ii;
//u v w
std::vector<ii> v[1000];

int cnts[10000]={0};
int a[2][1000];
int b[1000];
int main()
{
    BOOST;
    int n;
    cin>>n;
    FOR(i,0,n-1)
    {
        cin>>a[0][i];
    }
    FOR(i,0,n-1)
    {
        cin>>a[1][i];
    }
    FOR(i,0,n)
    {
        cin>>b[i];
    }
    int ans[1000]={0};
    int r[1000]={0};

    ans[0] = 0;
    FOR(i,1,n)
    {
        ans[i] = ans[i-1] + a[0][i-1];
    }
    r[n-1] = 0;
    for(int i = n-1-1;i>=0;i--)
    {
        r[i] = r[i+1] + a[1][i];
    }

    FOR(i,0,n)
    {
        cnts[i] = ans[i] + r[i] + b[i];
    }

    sort(cnts,cnts+n);
    int fina = cnts[0] + cnts[1];
    cout<<fina<<endl;



    return 0;
}