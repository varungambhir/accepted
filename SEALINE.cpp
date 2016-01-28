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
    int t;
    vector<int>a, v;
    vector<int>::iterator itx;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        v.clear();
        a.clear();
        FOR(i,0,n)
        {
            int x;
            cin>>x;
            a.push_back(x);
        }
        v.push_back(1);
        int cnt = 0;
        FOR(i,1,n)
        {   
            if(!a[i])
            {
                v.insert(v.begin(),i+1);
            }
            else 
            {

                itx = find(v.begin(),v.end(),a[i]);
                int diff1 = itx - v.begin() + 1;
                

                    //cout<<*(itx+1)<<" "<< *v.begin()<< endl;
                v.insert(itx+1,i+1);
                //debug(diff1);

                int len = v.size();
                //debug(len);
                cnt += std::min(diff1 , abs(len-diff1 - 1));

            }   
        }

        cout<<cnt<<endl;
    }
    return 0;
}