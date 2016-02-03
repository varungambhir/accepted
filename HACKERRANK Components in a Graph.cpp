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
#define L 2*stindex
#define R 2*stindex+1
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/
#define MAXN 50000
#define MOD 1000000007

int ranks[50000] = {0};
int parent[50000];

int find(int x)
{
  if(parent[x] != x)
    parent[x] = find(parent[x]);

  return parent[x];
}
int minrank;
int minindex;
int maxrank = INT_MIN;
int maxindex;
void unions(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);
    if( ranks[xroot] < ranks[yroot] )
        parent[xroot] = parent[yroot];
    else if ( ranks[xroot] > ranks[yroot] )
        parent[yroot] = parent[xroot];
    else
    {
        parent[yroot] = parent[xroot];
        ranks[xroot]++;
    }
    
}

bool visited[500000] = {0};
multiset<int> pars;
bool counted[500000] = {0};
int main(int argc, char const *argv[])
{
    BOOST;

    int n,t;
    cin >> n;
    FOR(i,0,2*n+1)
    {
        parent[i] = i;
    }

    FOR(i,1,n)
    {
        int x,y;
        cin >> x >> y;
        unions(x,y);
        visited[x]= 1;
        visited[y] = 1;
    }
    int mincount = INT_MAX;
    FOR(i,1,2*n)
    {
        if(visited[i])
        {
            parent[i] = find(i);
            pars.insert(parent[i]);
        }
    }
    
    //int mini = 0;
    int maxi = 0;
    int cnt = 0;
    
    //debug(maxindex);
    FOR(i,1,2*n)
    {
        //cerr << "i : " << i << " parent[i] : " << parent[i] <<endl;

        if(!counted[parent[i]] && visited[i] )
        {

            counted[parent[i]] = 1;
            mincount = min((int)pars.count(parent[i]) , mincount);  

            maxi = max(maxi,(int)pars.count(parent[i]));     

        }

    }

    cout << mincount << " "  << maxi << endl;

    return 0;
}




