#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L 2*node
#define R 2*node+1
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
#define MAXN 100005
#define MOD 1000000007

int main(int argc, char const *argv[])
{
    BOOST;
    int n,x,y;
    vector< pair< int,int> > v;

    cin>>n;
    FOR(i,0,n)
    {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(), v.end());
    if(n==1)
    {
        cout<<"-1\n";
    }
    else
    {
        int max_x , max_y , min_x , min_y;

        max_y = max_x = INT_MIN;
        min_y = min_x = INT_MAX;
        repstl(v)
        {
            max_x = max(max_x,it->first);
            max_y = max(max_y,it->second);

            min_x = min(min_x,it->first);
            min_y = min(min_y,it->second);
        }
        if(max_x==min_x || max_y==min_y)
            cout<<"-1\n";
        else
            cout<< abs(max_x-min_x)*abs(max_y-min_y)<<endl;
    }
    return 0;
}