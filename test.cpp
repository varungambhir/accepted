#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<time.h>
#include<queue>
#include<map>
#include<vector>
#define inf 1000000000
#define LL long long
#define ULL unsigned long long
#define dinf ~0uLL>>1
#define FO(i,n) for(LL i=0;i<n;i++)
#define FOD(i,n) for(LL i=n-1;i>=0;i--)
#define FOR(i,a,b,c) for(LL i=a;i<=b;i+=c)
#define FORD(i,a,b,c) for(LL i=a;i>=b;i-=c)
#define clr(a,b) memset(a,b,sizeof(a))
#define pi acos(-1.0)
#define H_J(a) ((a)*180.0/pi)
#define J_H(a) ((a)*pi/180.0)
#define lson l,mid,rt<<1
#define rson mid+1,r,(rt<<1)+1
#define eps 1e-8
#define zero(x) (abs(x)<eps?0:(x<0?-1:1))
#define printime printf("%.3lf\n",(double)clock() / CLOCKS_PER_SEC)
using namespace std;

const int maxn = 100005;
const LL mod = 1e9+7;

LL a[maxn],_10[15];
int b[maxn];

LL solve(LL x,int y,int k)
{
    LL ans=(_10[k]-1)/x;
    ans-=(_10[k-1]*(y+1)-1)/x;
    ans+=max(0LL,(_10[k-1]*y-1))/x;
    return ans+(y>0);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.int","r",stdin);
    //freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE
    _10[0]=1;
    for(int i=1;i<14;i++) _10[i]=_10[i-1]*10;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n/k;i++){
        scanf("%I64d",&a[i]);
    }
    LL ans=1;
    for(int i=1;i<=n/k;i++){
        scanf("%d",&b[i]);
        ans=(ans*solve(a[i],b[i],k))%mod;
    }
    cout<<ans<<endl;
    return 0;
}



