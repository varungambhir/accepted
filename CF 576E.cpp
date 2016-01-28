#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define F first
#define S second
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define MAX 500010
#define MOD 1000000007
#define endl "\n"
//#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef pair<int,int> pii;
double a[200010] , b[200010];

double bin(double x,int n)
{
    double pos , neg , value , mx;
    pos=neg=mx=value=0.0;

    FOR(i,0,n)
    {
        pos += (a[i] - x);
        neg += (a[i] - x);

        if(pos < 0.0)
            pos =0.0;
        if(neg > 0.0)
            neg = 0.0;

        if(value < pos)
        {
            value = pos;
            mx = pos;
        }
        if(value < abs(neg))
        {
            value = abs(neg);
            mx = neg;
        }
    }
    return mx;

}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.in","r",stdin);
    int n;
    cin>>n;
    FOR(i,0,n)
    {
        cin>>a[i];
    }
    double l = *min_element(a,a+n);
    double r = *max_element(a,a+n);
    double sum,ans,mid ;
    ans = (double)INT_MAX;
    double midprev=INT_MIN;
    FOR(t,0,100)
    {
        mid = (l+r)/2.0;
        sum = bin(mid,n);
        //if (sum==midprev) break;
        //debug(mid);
        //debug(sum);
        ans = min(ans, std::abs(sum));
        //debug(ans);
        if( sum > 0) // max(+s(i,j),-s(i,j)) shifted to left to reach min for x
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
        //midprev = sum;
    }

    cout<<setprecision(7)<<ans<<endl;

    return 0;
}