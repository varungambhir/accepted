#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long  long int
#define pii pair<int,int>
#define mpp make_pair
#define pb push_back
#define FOR(i,a,n) for(int (i)=(a);(i) < (n); ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define FF(i,a,n) for ((i) = (a); (i)<(n);++(i))
#define REP(i,a,n) for ((i) = (a); (i)<=(n);++(i))
#define V(x) vector<x>
#define Sd(x) scanf("%d",&x)
#define all(c) c.begin(),c.end()
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define F first
#define S second
#define PI acos(-1.0)
#define EPS 1e-9
#define Lf 2*r
#define Rg 2*r+1
#define M(x,i) memset(x,i,sizeof(x))
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define matrix vector< vector<ll> >

inline void inputfile()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
}
inline void cpp_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
#define MAX 100003
#define mod 1000000007
struct cmp1
{
    bool operator()( pii const &a ,  pii const &b)
    {
        return a.first > b.first;
    }
};

bool myfunc( pii const &a ,  pii const &b)
{
    return (a.first == b.first);
}

struct cmp2
{
    bool operator()( pii const &a ,  pii const &b)
    {
        return a.second < b.second;
    }
};

int main(int argc, char const *argv[])
{
    inputfile();cpp_input();
    vector< pii > v,a,b , list[2];
    vector<int> s;
    std::map<int, int> mp;
    int n;
    cin>>n;
    v.resize(2*n+1);
    FOR(i,0,2*n)
    {
        cin>>v[i].first;
        v[i].second = i;
        mp[v[i].first]++;
    }
    sort(v.begin(),v.end(),cmp1());

    FOR(i,0,2*n)
    {
        if(mp[v[i].first]==1)
        {
            a.push_back(v[i]);//unique values
        }
        else
        {
            b.push_back(v[i]);//multiple values
        }
    }
    s.resize(2*n+2);
    int f =0;
    repstl(a)
    {
        list[f].push_back(*it);
        f = !f;
    }
    repstl(b)
    {
        list[f].push_back(*it);
        f = !f;
    }

    repstl(list[0])
    {
        s[(*it).second] =1;
    }

    repstl(list[1])
    {
        s[(*it).second] =2;
    }

    list[0].erase(unique(all(list[0]) , myfunc ) , list[0].end()  );
    list[1].erase(unique(all(list[1]) ,   myfunc ) , list[1].end()  );

    cout<<list[0].size() * list[1].size()<<"\n";

    FOR(i,0,2*n)
    {
        cout<<s[i]<<" ";
    }

    return 0;
}
