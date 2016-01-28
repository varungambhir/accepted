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

ll a[2000100];
ll sum[2000100];
std::map<ll, ll> hash;
std::vector< pair<ll,ll> > v;

bool cmp(pair<ll,ll> a, pair<ll,ll> b)
{
    if(a.second == b.second)
        return a.first< b.first;    
    return a.second < b.second;
}
int main(int argc, char const *argv[])
{
    ll n;
    ll ind;
    bool flag = false;
    cin>>n;
    FOR(i,1,n+1)
    {
        cin>>a[i];
        if(!a[i])
            {
                flag = true;
                ind = i;
            }
    }
    sum[0] = 0;
    if(flag)
    {
        cout<<ind<<" "<<1<<endl;
        return 0;
    }

    FOR(i,1,n+1)
    {
        sum[i] = sum[i-1] + a[i];
        if(!sum[i])
        {
            v.push_back(make_pair(1,i));
            
        }
        if(hash[sum[i]]!=0)
        {
            //cout<< hash[sum[i]]+1 <<" "<< i-hash[sum[i]]<<endl;
            v.push_back(make_pair(hash[sum[i]]+1 ,i-hash[sum[i]]));
            hash[sum[i]] = i;
        }
        else
        {
            hash[sum[i]] = i;
        }
    }
    if(v.empty())
    {
        cout<<"-1\n";
    }
    else
    {
        sort(v.begin(), v.end(), cmp);
        //FOR(i,0,v.size()) cout<<v[i].first<<" "<<v[i].second<<endl;
        cout<<v[0].first<<" "<<v[0].second<<endl;
    }
    return 0;
}