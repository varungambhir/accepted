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
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define MAXN 1005
#define MOD 1000000007

int main(int argc, char const *argv[])
{
    BOOST;
    string s;
    int t=1;
    while(1)
    {
        cin>>s;
        if(s[0]=='-')
            break;
        int leftbrckt = 0;
        int ans;
        int invert_l_to_r = 0;
        FOR(i,0,s.length())
        {
            if(s[i]=='{')
            {
                leftbrckt++;
            }
            else
            {
                leftbrckt--;
                if(leftbrckt < 0)
                {
                    leftbrckt = 1;
                    invert_l_to_r++;
                }
            }
        }
        ans = invert_l_to_r + leftbrckt/2 ;

        cout<<t++<<". "<<ans<<endl;
    }

    return 0;
}