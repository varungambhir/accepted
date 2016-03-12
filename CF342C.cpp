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

 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/
#define MAXN 300005
#define MOD 1000000007

int a[550][550]={0};

void check(std::vector<int> &v)
{
    repstl(v)
        cout << *it << " ";
    cout << endl;
}

//http://www.codeforces.com/contest/625/problem/C
int main(int argc, char const *argv[])
{
    BOOST;
    int n,k;
    cin >> n >> k;
    int maxn = n*n;
    int first = maxn - (n-k);
    std::vector<int> v;
    v.emplace_back(first);
    FOR(i,1,n-1)
    {
        first -= (n-k+1);
        v.emplace_back(first);
    }

    //check(v);
    int no;
    FOR(i,0,n-1)
    {
        a[i+1][k] =  v[i];

        no = v[i];
        FOR(j,k+1,n)
        a[i+1][j] = no + (j-k);

    }

    no = v[n-1] -1;
    FOR(i,1,n)
    {
        ROF(j,k-1,1)
        {
            a[i][j] = no--;
        }
    }

    int sum_of_elems = std::accumulate(v.begin(), v.end(), 0);

    cout << sum_of_elems << endl;
    FOR(i,1,n)
    {
        FOR(j,1,n)
        cout << a[i][j] << " ";

        cout << endl;
    }


    return 0;
}