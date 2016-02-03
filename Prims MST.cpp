#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L 2*index
#define R 2*index+1
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
//#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << "\n"
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

And you run and you run to catch up with the Sun but it's sinking
Racing around to come up behind you again
The Sun is the same in a relative way, but you're older
Shorter of breath and one day closer to death

Every year is getting shorter, never seem to find the time
Plans that either come to naught or half a page of scribbled lines
- Time, Pink Floyd*/

#define MAXN 100010
#define MOD 1000000007
const int maxi = (int)1e9;
typedef pair<int,int> pii;
typedef pair<int,pii> iii;
vector<pii> G[9000];
int n,m;
int parent[9000],ranks[9000];
bool visited[9000];
int find(int x)
{
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void Union(int x,int y)
{
    int xroot = find(x);
    int yroot = find(y);

    if(xroot == yroot)
        return;

    if( ranks[xroot] < ranks[yroot] )
        parent[xroot] = parent[yroot];

    else if( ranks[xroot] > ranks[yroot] )
        parent[yroot] = parent[xroot];
    else
    {
        parent[yroot] = parent[xroot];
        ranks[xroot]++;
    }
}

int prims(int start)
{
    int cnt = n;
    int ans = 0;
    set<pii> Q;
    Q.insert(mp(0,start));
    while(cnt > 0 && !Q.empty())
    {
        pii top = *Q.begin();
        Q.erase(Q.begin());

        int d = top.first;
        int ind = top.second;
        if(visited[ind])
            continue;
        visited[ind] = 1;
        ans += d;
        cnt--;
        
        repstl(G[ind])
        {
            if(!visited[ (*it).first ])
            Q.insert(mp( (*it).second , (*it).first ));
        }
    }
    if(cnt != 0)
        cout << "ERROR\n";

    return ans;
}

int main(int argc, char const *argv[])
{
    BOOST;
    int t;
    //cin >> t;
    //while(t--)
    //{
        cin >> n >> m;
        FOR(i,0,n+1)
        {
            G[i].clear();
            ranks[i] = 0;
            visited[i] = 0;
            parent[i] = i;
        }
        int x,y,s,temp;
        FOR(i,1,m)
        {
            cin >> x >> y >> temp;
            G[x].push_back(mp(y,temp));
            G[y].push_back(mp(x,temp));
        }
        cin >> s;
        cout << prims(s) << endl;
    //}
    return 0;
}
