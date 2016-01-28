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

char temp[1001000];

int main(int argc, char const *argv[])
{
    BOOST;
    string s;
    cin>>s;
    int z;
    cin>>z;
    while(z--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        l--;
        r--;
        int len = r-l+1;

        k = k%len;
        if(k<0)
            k += len;
        int mod;

        FOR(i,l,r+1)
        {
            if(i+k>r)
            {
                mod = i+k - len;
            }
            else
            {
                mod = i+k;                
            }
            temp[mod] = s[i];
        }
        FOR(i,l,r+1)
        {
            s[i] = temp[i];
        }
        //debug(s);

    }

    cout<<s<<endl;
    return 0;
}