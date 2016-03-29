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

string p,f;

int A[1000]={0};
string Left,Right;
void merge(int lo, int mid, int hi)
{
    int n = mid - lo + 1;
    int m = hi - mid;

    
    Left.clear();
    Right.clear();
    Left.resize(n+1);
    Right.resize(m+1);
    int i,j,k;
    i = lo;
    j = mid+1;

    for(i = 0; i < n; i++)
        Left[i] = f[lo+i];
    Left[i] ='\0';

    for(i = 0 ; i < m; i++)
        Right[i] = f[mid+1+i];
    Right[i] = '\0';

    i = j = 0;
    k = lo;

    while(i < n && j < m)
    {
        if( A[Left[i] -'a'] < A[Right[j] -'a'])
            f[k++] = Left[i++];
        else
            f[k++] = Right[j++];
    }

    while(i < n)
    {
        f[k++] = Left[i++];
    }

    while(j < m)
    {
        f[k++] = Right[j++];
    }
}

void mergesort(int st,int en)
{
    if(st <  en)
    {
        int mid = (st+en)/2;
        mergesort(st,mid);
        mergesort(mid+1,en);
        merge(st,mid,en);
    }
}
//https://www.hackerearth.com/problem/algorithm/fast-sort-1/
int main(int argc, char const *argv[])
{
    BOOST;
    int t;
    cin >> t;
    while(t--)
    {
        p.clear(); f.clear();
        cin >> p >> f;

        FOR(i,0,25)
        {
           A[p[i]-'a'] = i+1;
        }

        mergesort(0,f.size()-1);

        cout << f << endl;
    }
    return 0;
}