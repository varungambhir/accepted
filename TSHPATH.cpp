#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define MAX 100000
#define MOD 1000000007

typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;


struct compare
{
    bool operator ()(const ii &a, const ii &b)
    {
        if(a.second==b.second)
            return a.first<b.first;
        return a.second < b.second;
    }
};

int main(int argc, char const *argv[])
{
    BOOST;
    ll s,n,p,nr,cost,m,r;
    string name,name1,name2;

    cin>>s;
    while(s--)
    {

        cin>>n;
        vector<pair<ll,ll> > v[n+1];
        map<string,ll> city;
        FOR(i,1,n+1)
        {
            cin>>name;
            city[name] = i;
            cin>>m;
            while(m--)
            {
                cin>>nr>>cost;
                v[i].push_back(ii(nr,cost));
            }
        }
        cin>>r;
        while(r--)
        {
            cin>>name1>>name2;
            ll src = city[name1] , dest = city[name2];

            std::vector<ll> D(n+1,LONG_MAX);

            set< ii ,compare>Q;
            Q.insert(ii(src,0));
            D[src] = 0;

            while(!Q.empty())
            {
                //pair<ll,ll> top = *Q.begin();
                ll index = Q.begin()->first;
                ll costs = Q.begin()->second;
                Q.erase(Q.begin());

                repstl(v[index])
                {
                    ll v2 = it->first;
                    ll cost = it->second;

                    if(D[v2] > D[index] + cost)
                    {
                        if(D[v2]!=LONG_MAX)
                        {
                            Q.erase(Q.find(ii(v2,D[v2]) ) );
                        }
                        D[v2] = D[index] + cost;
                        Q.insert(ii(v2,D[v2]));
                    }
                }
            }

            cout<<D[dest]<<"\n";

        }
    }
    return 0;
}
