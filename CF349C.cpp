#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
#define TRACE
#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif

#define MOD 1000000007


//http://codeforces.com/contest/667/problem/C
bool two[(int)1e5]={0};
bool three[(int)1e5]={0};
int main(int argc, char const *argv[])
{
    BOOST;
    string s1;
    cin >> s1;
    two[s1.size()] = three[s1.size()] = 1;
    
    set<string> ans;


    ROF(i,s1.size()-2,5)
    {
        string t = string(1,s1[i]) + string(1,s1[i+1]);
        if( (three[i+2]) || 

           (two[i+2] && t != (string(1,s1[i+2])+ string(1,s1[i+3]) ) ) 
           
           )
        {
            ans.insert(t);
            two[i] = 1;
        }

        string t2 = string(1,s1[i]) + string(1,s1[i+1]) + string(1,s1[i+2]);

        if(
           (two[i+3]) || 
           (three[i+3] && t2 != (string(1,s1[i+3])+ string(1,s1[i+4])+string(1,s1[i+5]) ) )
           )
        {

            ans.insert(t2)  ;
            three[i] = 1;
        }

    }
    


    cout << ans.size() << endl;
    for(string p: ans)
        cout << p << endl;
    return 0;
}