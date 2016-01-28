#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define F first
#define S second
#define L 2*node
#define R 2*node+1
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
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
#define MAX 1010
#define MOD 1000000007

int main(int argc, char const *argv[])
{
    int a[100000+5];
    bool flag[100000+5] = {0};
    int n;
    std::vector<int> odd,even;
    scanint(n);
    FOR(i,0,n)
    {
        scanint(a[i]);
        if(a[i]&1)
        {
            odd.push_back(a[i]);
        }
        else
        {
            even.push_back(a[i]);
        }
    }
    set<int> s;
    map<int,int> initial, M;
    FOR(i,0,n)
    {
        initial[a[i]] = i;
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end()); 

    FOR(i,0,odd.size())
    {
        M[initial[odd[i]]] = 2*i;
    }
     FOR(i,0,even.size())
    {
        M[initial[even[i]]] = 2*i +1 ;
    }

    int total = 0;

    FOR(i,0,n)
    {
        if(!flag[i])
        {
            int start = i;
            flag[i] = true;
            int stop = M[i];
            flag[stop] = true;
            s.clear();
            s.insert(start);
            s.insert(stop);
            while(start != stop)
            {
                stop = M[stop];
                flag[stop] = true;
                s.insert(stop);
            }

            total = total + s.size() - 1;
        }
    }

    printf("%d\n",total);
    return 0;
}