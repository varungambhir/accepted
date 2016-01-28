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

int a[1000010] = {0};

int lsubseq(int n)
{
    int chk = !a[0];
    int val = 1;
    int cur;
    FOR(i,1,n)
    {
        cur = a[i];
        if(cur == chk)
        {
            val++;
            chk = !chk;
        }
    }
    return val;
}

int main()
{
    //BOOST;
    int n;
    char s;
    //8
//    10000011
    cin >> n;
    int ans,val;
    
    FOR(i,0,n)
        {
            cin >> s;
            a[i] =(int) s-'0';
        }

    val = lsubseq(n);
    ans = val;
    //debug(ans);

    int start, ends;
    start = 1;
    int chk = !a[0];

    while(start < n)
    {
        //debug(start);
        ends = start;
        if( a[start] == chk )
        {
            start++;
            chk = !chk;
            //debug(chk);
        }
        else
        {
            //debug(chk);
            while( ends < n && a[ends] != chk)
            {
                chk = !chk;
                ends++;
              //  debug(chk);
                //debug(ends);
            }
            
            if( ends < n && a[ends-1] == a[ends])
                ans = max(val+2,ans);
            else
                ans = max(val+1 , ans);
            //debug(ends);
            start = ends; //+1
            chk = a[ends-1] ; //!a[ends]
        }
    }

    cout<<ans<<"\n";

    return 0;
}
