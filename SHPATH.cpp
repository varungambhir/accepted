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

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define gc getchar_unlocked
    template <typename T>
void scanint(T &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

struct compare
{
    bool operator ()(const ii &a, const ii &b)
    {
        if(a.second==b.second)
            return a.first<b.first;
        return a.second < b.second;
    }
};

std::vector<ii> v[10005];
map<string,int> city;
int D[10005];
set< ii ,compare>Q;

int main(int argc, char const *argv[])
{
    int s,n,p,nr,cost,m,r;
    //string name,name1,name2;
    char name[10000] , name1[10000] , name2[10000];
    scanint(s);
    while(s--)
    {

        scanint(n);
        FOR(i,0,n+1)
        v[i].clear();
        city.clear();
       
        FOR(i,1,n+1)
        {
            scanf("%s",name);
            city[string(name)] = i;
            scanint(m);
            while(m--)
            {
                //cin>>nr>>cost;
                scanint(nr);
                scanint(cost);
                v[i].push_back(ii(nr,cost));
            }
        }
        scanint(r);
        while(r--)
        {
            //cin>>name1>>name2;
            scanf("%s%s",name1,name2);
            int src = city[string(name1)] , dest = city[string(name2)];

            FOR(i,0,n+1)
            D[i] = INT_MAX;

            Q.clear();
            Q.insert(ii(src,0));
            D[src] = 0;

            while(!Q.empty())
            {
                //pair<ll,ll> top = *Q.begin();
                int index = Q.begin()->first;
                int costs = Q.begin()->second;
                Q.erase(Q.begin());

                repstl(v[index])
                {
                    int v2 = it->first;
                    int cost = it->second;

                    if(D[v2] > D[index] + cost)
                    {
                        if(D[v2]!=INT_MAX)
                        {
                            Q.erase(Q.find(ii(v2,D[v2]) ) );
                        }
                        D[v2] = D[index] + cost;
                        Q.insert(ii(v2,D[v2]));
                    }
                }
            }

            printf("%d\n",D[dest]);

        }
    }
    return 0;
}
