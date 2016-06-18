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

#define MOD 1000000007

// Flatten Binary tree leetcode
#define MAXN 1010

const map<char, array<bool,4> > token = 
{
    {'+', {1, 1, 1, 1}},
    {'-', {0, 1, 0, 1}},
    {'|', {1, 0, 1, 0}},
    {'^', {1, 0, 0, 0}},
    {'>', {0, 1, 0, 0}},
    {'<', {0, 0, 0, 1}},
    {'v', {0, 0, 1, 0}},
    {'L', {1, 1, 1, 0}},
    {'R', {1, 0, 1, 1}},
    {'U', {0, 1, 1, 1}},
    {'D', {1, 1, 0, 1}},
    {'*', {0, 0, 0, 0}}
};

const array<int,4> dx = {0,1,0,-1};
const array<int,4> dy = {-1,0,1,0};

bool ok(char from, char to,int rotate, int dir)
{
    int opposite = (dir+2+4)%4;
    return token.at(from)[(dir-rotate+4)%4] && token.at(to)[(opposite -rotate + 4)%4];
}

bool seen[1002][1002][5];

int main(int argc, char const *argv[])
{ 
    BOOST;
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        if(n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        ll sum = 0;
        for(ll i = 1; i*i <= n; i++)
        {
            if( n%i == 0)
            {
                if(i == 1)
                    sum += i;
                else if(i*i == n)
                    sum = sum + i;
                else
                    sum = sum + i + n/i;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
