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

string a[20];

long double ans[20];

long double EPS = 1e-12;

int sign(long double x)
{
    return x < -EPS ? -1 : (x > EPS ) ;
}

int main(int argc, char const *argv[])
{
   
    a[1] = "x^y^z";
    a[2] = "x^z^y";
    a[3] = "(x^y)^z";
    a[4] = "(x^z)^y";

    a[5] = "y^x^z";
    a[6] = "y^z^x";
    a[7] = "(y^x)^z";
    a[8] = "(y^z)^x";

    a[9] = "z^x^y";
    a[10] = "z^y^x";
    a[11] = "(z^x)^y";
    a[12] = "(z^y)^x";


    BOOST;
    long double x,y,z;

    cin >> x >> y >> z;

    ans[1] = pow(y, z) * log(x);
    ans[2] = pow(z, y) * log(x);
    ans[3] = y * z * log(x);
    ans[4] = y * z * log(x);
    ans[5] = pow(x, z) * log(y);
    ans[6] = pow(z, x) * log(y);
    ans[7] = x * z * log(y);
    ans[8] = x * z * log(y);
    ans[9] = pow(x, y) * log(z);
    ans[10] = pow(y, x) * log(z);
    ans[11] = y * x * log(z);
    ans[12] = y * x * log(z);

    long double maxi = ans[12];
    int ind = 12;

    ROF(i,11,1)
    {
        if(  sign(ans[i] - maxi) >= 0 )
        {
            maxi = ans[i];
            ind = i;
        }
    }

    cout << a[ind] << endl;

    return 0;
}