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
#define L 2*index
#define R 2*index+1
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define endl "\n"
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

inline void inputfile()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
}

 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun

And you run and you run to catch up with the sun
But it's Sinking
Racing around to come up behind you again
The Sun is the same in a relative way, but you're older
Shorter of breath and one day closer to death

Every year is getting shorter, never seem to find the time
Plans that either come to naught or half a page of scribbled lines
- Time, Pink Floyd*/

std::vector<string> p,f;

map<string, int> A;

vector<string> Left,Right;
int merge(int lo, int mid, int hi)
{
    int n = mid - lo + 1;
    int m = hi - mid;


    Left.clear();
    Right.clear();
    int i,j,k;
    i = lo;
    j = mid+1;

    for(i = 0; i < n; i++)
    {
        Left.push_back(f[lo+i]);
    }

    for(i = 0 ; i < m; i++)
    {
        Right.push_back(f[mid+1+i]);
    }

    i = j = 0;
    k = lo;
    int invcnt = 0;
    while(i < n && j < m)
    {
        if( A[Left[i]] <= A[Right[j]])
            f[k++] = Left[i++];
        else
        {
            f[k++] = Right[j++];
            //trace2(mid,i);
            invcnt += (n - i); // n = mid - lo + 1
        }
    }

    while(i < n)
    {
        f[k++] = Left[i++];
    }

    while(j < m)
    {
        f[k++] = Right[j++];
    }

   /* if(invcnt > 0 )
    {
        cout <<"-----\n";
        cout << invcnt << endl;
        FOR(i,lo,hi)
        {
            cout << f[i] << " ";
        }

        cout << endl;
    }
*/
    return invcnt;
}

int mergesort(int st,int en)
{
    int inv = 0;
    if(st <  en)
    {
        int mid = (st+en)/2;
        inv += mergesort(st,mid);
        inv += mergesort(mid+1,en);
        inv += merge(st,mid,en);
    }
    return inv;
}

int main(int argc, char const *argv[])
{
    BOOST;
    //inputfile();

    int n,t;
    cin >> t;

    while(t--)
    {
        cin >> n;
        string temp;
        p.clear(); f.clear();
        A.clear();
        FOR(i,1,n)
        {
            cin >> temp;
            f.push_back(temp);
        }

        FOR(i,1,n)
        {
            cin >> temp;
            p.push_back(temp);
        }

        FOR(i,0,n-1)
        {
         A[p[i]] = i+1;
        }


         int invcnt = mergesort(0,n-1);

       /*  FOR(i,0,n-1)
         {
            cout << f[i] << " ";
         }

         cout << endl;
        */
         cout << invcnt << endl;
    }
 return 0;
}
