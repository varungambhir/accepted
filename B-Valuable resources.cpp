#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define Sd(x) scanf("%d",&x)
#define f first
#define s second
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define MAX 1000005
#define MOD 1000000007


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n;
    cin>>n;
    ll a[n],b[n];
    FOR(i,0,n)
    {
        cin>>a[i]>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);

    ll d2  = max( (a[n-1] - a[0])*(a[n-1] - a[0]) , (b[n-1] - b[0])*(b[n-1] - b[0]) );
    cout<<d2<<"\n";

    return 0;
}