#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L 2*stindex
#define R 2*stindex+1
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/
#define MAXN 1000010
#define MOD 1000000007
int a[MAXN];
int sievesize;
int Prime[1100000];
int pos[5010001];
#define prime(i) ((Prime[i>>5])&(1<<(i&(31))))
#define set(j) (Prime[j>>5]|=(1<<(j&(31))))
#define LIM 86100000
#define SLIM 9278
void sieve2()
{
        int i, j, m, n, t,x,k,l,h;
        set(1);
        pos[1]=2;
        pos[2]=3;
        for(k=2,l=3,i=5; i<=SLIM; k++,i=3*k-(k&1)-1)
                if(prime(k)==0)
                {
                        pos[l++]=i;
                        for(j=i*i,h=((j+2)/3); j<=LIM; h+=(k&1)?(h&1?((k<<2)-3):((k<<1)-1)):(h&1?((k<<1)-1):((k<<2)-1)),j=3*h-(h&1)-1)
                        set(h);
                }
       
        i=3*k-(k&1)-1;
        for(; i<=LIM; k++,i=3*k-(k&1)-1)
        if(prime(k)==0)
        pos[l++] = i;

        sievesize = l;
        return ;
}
ll f[10000050],n,h,t,m;
ll v,b,e,p;
ll w,l,d,i;
ll j,recsum[1000005],arr[1000005];
void sieve() 
{
    f[0]=1;f[1]=1;
    for (ll i=2; i<=1000000;i++)
    {
        if (!f[i]) 
        {
            f[i] = i;
            for (ll j = i*i; j<=1000000; j+= i)
            {
                if(!f[j])        
                    f[j] = i;
            }
        }
    }
}
ll result=0;
void rec(ll num,ll sum)
{
    if(num>=n)
    {
        if(sum%2==0)
            result+=sum;
        return;
    }
    rec(num+1,sum);
    rec(num+1,sum+recsum[arr[num]]);
    return;
}
int main()
{
    sieve();
    recsum[1]=0;    recsum[2]=1;    recsum[3]=2;
    ll cnt=0;
    for(i=4;i<=1000000;i++)
    {
        cnt=0;        v=i;
        while(v>1)
        {
            cnt++; v=v/f[v];
        }
        recsum[i]=cnt+recsum[i-1];
    }
    cin>>n;
    for(i=0;i<n;i++)
        cin>>arr[i];
    rec(0,0);
    cout<<result<<"\n";
    return 0;
}               