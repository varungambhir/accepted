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

std::vector<int> v[(int)1e6];
bool visit[(int)1e6] = {0} ;
std::vector<int> L;

void dfs(int i = 1,int dep = 0)
{
    //trace2(i,dep);
    if(visit[i]) return;
    visit[i] = 1;

    if(v[i].size() == 1)
    {
        L.push_back(dep);
        return;
    }

    FOR(j,0,v[i].size()-1)
    {
        int w = v[i][j];
        //cerr << w << endl;
        dfs(w,dep+1);
    }
}
//http://www.codeforces.com/contest/622/problem/E
int main(int argc, char const *argv[])
{
    BOOST;
    int n,x,y;
    cin >> n;
    FOR(i,0,n-2)
    {
        cin >> x >> y;
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }

    int maxi = 0;
    visit[1] = 1;
    std::vector<int> ans;
    FOR(i,0,v[1].size()-1)
    {
        L.clear();
        dfs(  v[1][i] ,1);
        sort(L.begin(),L.end());
             
        FOR(j,0,L.size()-1)
        {   
            if(!j)
                continue;
            else
                L[j] = max(L[j],L[j-1] + 1);
        }
        repstl(L)
            ans.push_back(*it);
        maxi = max(maxi,(ans.back()));
        
    }

    cout << maxi << "\n";
    return 0;
}