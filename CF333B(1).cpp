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
#define MAXN 1010
#define MOD 1000000007
int a[(int)1e6];
int d[(int)1e6];

int main(int argc, char const *argv[])
{
    BOOST;
    int x,n,maxlen,j;
    j=maxlen=0;
    cin>>n;
    std::vector<int> v;
    multiset<int> s;
    FOR(i,0,n)
    {
        cin>>x;
        v.push_back(x);
        s.insert(x);

        while(!s.empty() && ( abs(*s.rbegin() - *s.begin() ) > 1))
        {
            s.erase(s.find( v[j] ) );
            j++;
        }
        maxlen = max(maxlen, (int)s.size());
    }

    cout<<maxlen<<endl;
    return 0;
}

