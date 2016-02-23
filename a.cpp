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

 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/
#define MAXN 3000005
#define MOD 1000000007

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

struct node{
    int l,r;
    bool operator <(const node& b) const{
        return r<b.r;
    }
};

const int MX=int(1e5)+10;
const LL MOD=1000000007;


LL s[MX];
node b[MX];
int eb[MX];
int n,m;

void add(int x,LL adn){
    while (x<=m+1){
        s[x]+=adn;
        s[x]%=MOD;
        x+=x&(-x);
    }
}

LL getsum(int x){
    LL ret=0;
    while (x>0){
        ret+=s[x];
        ret%=MOD;
        x-=x&(-x);
    }
    return ret;
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        scanf("%d%d",&b[i].l,&b[i].r);
    }
    b[m+1].l=0; b[m+1].r=0;
    sort(b+1,b+m+2);
    for (int i=1;i<=m+1;i++){
        eb[i]=b[i].r;
    }
    add(1,1LL);
    for (int i=2;i<=m+1;i++){
        int x,y;
        x=lower_bound(eb+1,eb+i,b[i].l)-eb-1;
        y=lower_bound(eb+1,eb+i,b[i].r)-eb-1;
//        cout<<x<<' '<<y<<endl;
        add(i,getsum(y)-getsum(x));
    }
    if (b[m+1].r==n){
        int y=lower_bound(eb+1,eb+m+2,n)-eb-1;
        printf("%I64d",(getsum(m+1)-getsum(y)+MOD)%MOD);
    }else{
        printf("0");
    }
}