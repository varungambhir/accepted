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
- Time, Pink Floyd*/
#define MAXN 100010
#define MOD 1000000007
const int maxi = (int)1e9;
vector<pair<int,int> > G[9000];
bool visited[9000];
int n,m;
int D[9000];

void dijkstras(int s)
{
    FOR(i,0,n+1)
    D[i] = maxi;
    D[s] = 0;
    set< pair<int,int> > Q;
    Q.insert(mp(0,s));
    set< pair<int,int> >::iterator it2;
    while(!Q.empty())
    {
        pair<int,int> top = *Q.begin();
        Q.erase(Q.begin());
        int d = top.first;
        int ind = top.second;
        //trace2(ind,d);
        repstl(G[ind])
        {
            int ind2 = (*it).first;
            int dist = (*it).second;

            if(D[ind2] > D[ind] + dist)
            {
                if(D[ind2] != maxi)
                {
                    it2 = Q.find(mp(D[ind2],ind2));
                    if(it2 != Q.end())
                    Q.erase(it2);
                }

                D[ind2] = D[ind] + dist;
                Q.insert(mp(D[ind2],ind2));
            }
        }

    }

    FOR(i,1,n)
    {
        if(i != s)
        {
            if(D[i] != maxi)
                cout << D[i] << " ";
            else
                cout << "-1 ";
        }
    }
    cout << "\n";
    return;
}

int main(int argc, char const *argv[])
{
    BOOST;
    int t;
    cin >> t;
    while(t--)
    {
        int x,y,s,r,temp;
        cin>>n >> m;
        FOR(i,0,n+1)
            G[i].clear();
        FOR(i,1,m)
        {
            cin >> x >> y >> temp;
            G[x].push_back(mp(y,temp));
            G[y].push_back(mp(x,temp));
        }

        cin >> s;

        dijkstras(s);
    }
    return 0;
}
