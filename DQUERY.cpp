/*
Written by : Ashish Sareen
*/
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
//#define L 2*index
//#define R 2*index+1
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

And you run and you run to catch up with the Sun but it's sinking
Racing around to come up behind you again
The Sun is the same in a relative way, but you're older
Shorter of breath and one day closer to death

Every year is getting shorter, never seem to find the time
Plans that either come to naught or half a page of scribbled lines
- Time, Pink Floyd*/

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
#define N 311111
#define A 1111111
#define BLOCK 555 //sqrt(N)

int cnt[A] , a[N], ans[N] , answer = 0;

struct node
{
    int L, R, i;
}q[N];

bool cmp(const node &x,const node &y)
{
    if(x.L/BLOCK != y.L/BLOCK)
    {
        //different blocks so sort by block
        return x.L/BLOCK < y.L/BLOCK;
    }
    //same block sort by R value
    return x.R < y.R;
}

void add(int position)
{
    cnt[a[position]]++;
    if(cnt[a[position]] == 1)
        answer++;
}

void remove(int position)
{
    cnt[a[position]]--;
    if(cnt[a[position]]==0)
        answer--;
}

int main(int argc, char const *argv[])
{
    int n,m;
    scanint(n);
    FOR(i,0,n-1)
    scanint(a[i]);

    scanint(m);
    FOR(i,0,m-1)
    {
        scanint(q[i].L);
        scanint(q[i].R);
        --q[i].L;
        --q[i].R;
        q[i].i = i;
    }
    memset(cnt,0,sizeof(cnt));
    sort(q,q+m,cmp);

    int currentL = 0 , currentR = 0;
    FOR(i,0,m-1)
    {
        int  L = q[i].L , R = q[i].R;
        while(currentL < L)
        {
            remove(currentL);
            currentL++;
        }

        while(currentL > L) 
        {
            add(currentL-1);
            currentL--;
        }

        while(currentR <= R)
        {
            add(currentR);
            currentR++;
        }

        while(currentR > R+1)
        {
            remove(currentR-1);
            currentR--;
        }
        ans[ q[i].i ] = answer;
    }
    FOR(i,0,m-1)
    {
        printf("%d\n",ans[i]);
    }

    return 0;
}