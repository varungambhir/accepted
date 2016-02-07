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



//http://codeforces.com/contest/86/problem/D


#define  N 200010
#define A 1000010
int BLOCK;

struct node
{
    int L,R,i;
}q[N];



int cnt[A] , a[N] ;
ll ans[N] ;
ll sum =0;

bool cmp(const node &x, const node &y)
{
    if(x.L/BLOCK != y.L/BLOCK)
    {
        return x.L/BLOCK < y.L/BLOCK;
    }
    return x.R  < y.R;
}

void add(int position)
{
    sum -= (cnt[a[position]]*1LL)*cnt[a[position]]*a[position];
    cnt[a[position]]++;
    sum += (cnt[a[position]]*1LL)*cnt[a[position]]*a[position];
}

void remove(int position)
{
   sum -= (cnt[a[position]] * 1LL) * cnt[a[position]] * a[position];
   cnt[a[position]]--;
   sum += (cnt[a[position]] *1LL) * cnt[a[position]] *a[position];
}

int main(int argc, char const *argv[])
{

    int t,n;
    SD(n);
    SD(t);
    BLOCK = sqrt(n);
    FOR(i,0,n-1)
    SD(a[i]);

    FOR(i,0,t-1)
    {
        SD(q[i].L);
        SD(q[i].R);
        q[i].L--;
        q[i].R--;
        q[i].i = i;
    }

    sort(q,q+t,cmp);

    int currentL = q[0].L , currentR = q[0].R;
    FOR(i,currentL,currentR)
    add(i);

    ans[q[0].i] = sum;

    FOR(i,1,t-1)
    {
        int L = q[i].L  , R = q[i].R;

        while(currentL < L)
        {
            remove(currentL);
            currentL++;
        } 

        while(currentL > L)
        {
            currentL--;
            add(currentL);
        }

        while(currentR < R)
        {
            currentR++;
            add(currentR);
        }

        while(currentR > R )
        {
            remove(currentR);
            currentR--;
        }

        ans[q[i].i] = sum;
    }
    
    FOR(i,0,t-1)
    {
        printf("%I64d\n",ans[i]);
    }
    return 0;
}