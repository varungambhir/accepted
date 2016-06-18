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

int a[100005]={0};

ll modpow(ll a, ll b, ll mod=((ll)1e9+7))
{
    ll ret = 1;

    while(b > 0)
    {
        if(b&1)
            ret = (ret*a)%mod;
        a = (a*a)%mod;
        b = b/2;
    }
    return ret%mod;

}

bool brute_forces(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    bool c = 0;
    FOR(i,0,n-1)
    {
        int j;
        for(j = 0; j < m && i+j<n; j++)
        {
            if(text[i+j] != pattern[j])
            {
                break;
            }
        }
        if(j == m)
        {
            c = 1;
            break;
        }
    }
    return c;
}

//correctly calculates a mod b even when a<0
inline int amodb(ll a,ll b =((ll)1e9+7))
{
    return (a%b + b)%b;
}

bool rbkrp(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    bool c = 0;
    //B base
    //M mod

    ll B = 10;
    ll M = 1e9+7;

    if(n < m) return false; //no  match possible
    
    ll hp = 0; //hash value of pattern
    FOR(i,0,m-1)
    hp = amodb(hp*B + pattern[i],M);

    ll ht = 0;
    FOR(i,0,m-1)// hash value of first segment of text of length m
    ht = amodb(ht*B + text[i],M);

    if(ht == hp) // hashes match need to check char by char
    {
        if( brute_forces(text.substr(0,m),pattern.substr(0,m)))
            return true;
    }

    //start "rolling hash" for every net character in
    // the text calculate the hash value of the next segment 
    // of length m ;
    //E = (Bm - 1) modulo M
    ll E = modpow(B,m-1,M);
    FOR(i,m,n-1)
    {
        ht = amodb( ht - amodb(text[i-m]*E) ,M);
        ht = amodb( ht * B ,M);
        ht = amodb( ht + text[i],M);

        trace3(i,n,m);
        if(ht == hp)
        { //some out of rang eerror
          trace4(i,n,m,i-m);
            if(brute_forces(text.substr(i-m+1,m),pattern.substr(i-m+1,m)) ) 
                return true;
        }
    }
    return false;
} 

int main() 
{
    BOOST;
    string s1 = "ABCDFGHASDS";
    string s2 = "DS"; 


    if(rbkrp(s1,s2))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}