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
#define MAXN 10000005
#define MOD 1000000007

string s[1100];
int main(int argc, char const *argv[])
{
    BOOST;
    int n;
    bool flag;
    cin>>n;
    FOR(i,0,n)
        cin>>s[i];

    int fans = -1;
    FOR(i,0,26)
    {
        FOR(j,0,26)
        {
            int ans = 0;

            FOR(k,0,n)
            {
                flag = false;
                //cout<<s[k]<<endl;
                FOR(l,0,s[k].length())
                {
                    if( (s[k][l] == (i+'a')) || (s[k][l]==(j+'a')) )
                    {
                        ;
                    }
                    else
                    {
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                {
                    ans = ans + s[k].length();
                    //debug(ans);
                }
            }

            fans = std::max(ans,fans);
        }
    }
    cout<<fans<<"\n";
    return 0;
}