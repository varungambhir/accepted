#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define Sd(x) scanf("%d",&x)
#define f first
#define s second
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define MAX 1000005
#define MOD 1000000007

typedef pair<int,int> pii;

bool a[1000002]={0};
int k,l,m,temp;

inline void rec()
{
    a[1]=a[k]=a[l]= 1;//A

    FOR(i,2,k)
    {
        a[i] =  !a[i-1];
    }
    FOR(i,k+1,l)
    {
        a[i] = std::max(!a[i-k],!a[i-1]);
    }
    FOR(i,l+1,1000001)
    {
        a[i] = std::max(!a[i-1],!a[i-k]);
        a[i] = std::max(a[i],!a[i-l]);
    }

}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

        
    cin>>k>>l>>m;
    //memset(a,-1,sizeof(a));
    rec();
    char s[m+1];
    FOR(i,0,m)
    {
        cin>>temp;
        if(a[temp])
            s[i]='A';
        else
            s[i]='B';
    }
    s[m]='\0';
    cout<<s<<"\n";
    return 0;
}