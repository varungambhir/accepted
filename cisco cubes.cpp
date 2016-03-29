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

int main()
{
    ll n,val;
    cin>>n;
    vector<ll> v;
    vector<ll> T1,T2,T3;
    ll t1,t2,t3;
    t1=t2=t3 =0;
    FOR(i,1,n)
    {
        cin>>val;
        v.pb(val);
    }
    sort(all(v));
    FOR(i,0,n-1)
    {
        val=v[i];
        t1 += -(val*val*val);
        t2 += val;
        t3 += -(val*val);
        T1.pb(t1);
        T2.pb(t2);
        T3.pb(t3);
    }

    ll ans = 0;
    ll minx = LLONG_MAX;
    FOR(i,0,n-1)
    {
        ll p = (v[i]*v[i]*v[i])*(i);
        if(i-1 >= 0)
            p += T1[i-1];
        if(i-1 >= 0)
            p -= 3*v[i]*(v[i]*T2[i-1]+T3[i-1]);

        ll q = -(v[i]*v[i]*v[i])*(n-i-1);
        q -= T1.back() - T1[i];
        q += 3*v[i]*( v[i]*(T2.back() - T2[i]) + T3.back() - T3[i]);
        if(p+q < minx)
            minx = p+q, ans = v[i];
    }
    
    ll a = (v[0] + v[n-1])/2;
    ll b = ans;
    ll ansA = 0;
    ll ansB = 0;
    
    FOR(i,0,n-1)
    {
        val = abs(v[i] - a);
        ansA += pow(val,3);
        val = abs(v[i] - b);
        ansB += pow(val,3);
    }
    if(ansA < ansB)
        cout<<a;
    else
        cout<<b;
    
    return 0;
}