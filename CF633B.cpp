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

ll t,f;
ll ans[1000010];
ll cnt[1000010]={0};
ll cnf[1000010]={0};
//http://codeforces.com/contest/633/problem/B
int main(int argc, char const *argv[])
{
    BOOST;
    ll m;
    cin >> m;
    for(ll i = 1 ; i <= 1000000 ; i++)
    {
        ll k =  i;
        t = 0;
        if( !(k&1))
        {
            while(!(k&1) && k>0)
            {
                t++;
                k >>=1;
            }
            
        }
        cnt[i] = cnt[i-1] + t;
        f = 0;
        if(k%5 == 0)
        {
            while((k%5 == 0) && k>0)
            {
                f++;
                k /= 5;
            }
        }
        cnf[i] = cnf[i-1] + f;
    }

    int i = lower_bound(cnf+1,cnf+1000000+1,m) - cnf;
    int j = upper_bound(cnf+1,cnf+1000000+1,m) - cnf;

    
    cout << (j-i) << endl;
    FOR(k,i,j-1)
    {
        cout << k << " ";
    }
    cout << endl;
    
    
    return 0;
}