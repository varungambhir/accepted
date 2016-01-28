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

int main(int argc, char const *argv[])
{
    BOOST;
    int n,k;
    while(cin>>n>>k)

    {
        if(k==1 && n==1)
        {
            cout<<"a";
        }
       else if(k == 1 || (n<k))
        {
            cout<<"-1";
        }
        else if(k==2)
        {
            bool f = true;
            FOR(i,0,n)
            {
                if(f)
                    cout<<"a";
                else
                    cout<<"b";
                f = !f;
            }
        }
        else if( k > 2 && k<=26)
        {
            int kd = k - 2;
            bool f = true;
            FOR(i,0,n-kd)
            {
                if(f)
                    cout<<"a";
                else
                    cout<<"b";
                f = !f;
            }
            char c = 'c';
            FOR(i,n-kd,n)
            {
                cout<<c;
                c += 1;
            }
        }
        else
        {
            cout<<"-1";
        }
        cout<<"\n";
    }
    return 0;
}