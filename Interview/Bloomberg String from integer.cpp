#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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

//Bloomberg Print all strings (a = 1, b = 2 ...)
/* 111
a
k
ak
ka
*/

map<string,char> dict;
string s1;

string to_strings(int x)
{
    string ans = "";
    while(x > 0)
    {
        int r = x%10;
        ans = ans + (char)(r + '0');
        x/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


void prints(string sol,int index ,int len) //0 1 , 1 -> 2 characters
{
    //trace3(index,sol,len);
    if(index >= len)
    {
        cout << sol << endl;
        return;
    }

    prints(sol + dict[s1.substr(index,1)] , index+1 , len);
    if(index + 2 <= len) {
        prints(sol + dict[s1.substr(index,2)] , index + 2 , len);
    }


    return;
}


void rec()
{
    int l = s1.size();
    dict.clear();
    FOR(i,0,25)
    {
        dict[to_strings(i+1)] = (char)('a'+i);
    }
    prints(string(1,dict[s1.substr(0,1)]),1,l);

    int x = (int)((s1[1] - '0') + (int)(s1[0] - '0')*10);
    
    if(  x <= 26  ){

        prints(string(1,dict[s1.substr(0,2)]),2,l);

    }

    return;
}


int main() {
    BOOST;
    cin >> s1;
    rec();
    return 0;
}
