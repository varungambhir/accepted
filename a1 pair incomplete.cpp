#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define Sd(x) scanf("%d",&x)
#define F first
#define S second
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define MAX 1000100
#define MOD 1000000007
#define endl "\n"
typedef pair<int,int> pii;
#define gc getchar_unlocked
    template <typename T>
void scanint(T &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
        if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
        if(neg) x=-x;
}
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

int a[100010];
int main(int argc, char const *argv[])
{
    int t;
    ll n;
    scanint(t);
    int pos = (int)log2(1000001);
    //debug(pos);
    while(t--)
    {
        scanint(n);
        ll count = n*(n-1);
        FOR(i,0,n)
        {
            scanint(a[i]);
        }
        ll cnt = 0;
        FOR(i,0,pos+1)
        {
            cnt=0;

            FOR(j,0,n)
            {

                if((CHECK_BIT(a[j],i)))
                {
                    cnt++;
                }
            }
            debug(cnt);
            if(cnt>1)
                count -= (cnt*2);
        }

        printf("%lld\n",count);
    }
    return 0;
}