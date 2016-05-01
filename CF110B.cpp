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

#define MOD 1000000007


const int maxval = 1100;

/*
void update(double *tree,int idx,int val)
{
    for(;idx <= maxval; idx = idx + (idx & (-idx)) )
    {
        tree[idx] += val;
    }
}

double queryfenwick(double *tree,int idx)//sum 1...idx
{
    double sum = 0;
    for(;idx <= maxval ; idx = idx - (idx & (-idx)))
    {
        sum += tree[idx];
    }
    return sum;
}

double query(int p)
{
    return queryfenwick(t1, p)*p - queryfenwick(t2, p);
}

double rangequery(int b,int a = 1)// b,a
{
    return query(b) - query(a-1);
}
*/

int AC[(int)1e6];
int DEF[(int)1e6];
int arr[(int)1e6];
set<int> criminal;

//http://codeforces.com/contest/156/problem/B

//110 Div 1 B
int main(int argc, char const *argv[])
{
    BOOST;
    int n,m,x;
    cin >> n >> m;
    int tot_just= 0;
    FOR(i,1,n)
    {
        cin >> x;
        arr[i] = x;
        if(x < 0)
            DEF[abs(x)]++ , tot_just++;
        else
            AC[abs(x)]++;
    }   
    int sum;
    FOR(i,1,n)
    {
        sum = AC[i];
        sum = sum + tot_just - DEF[i];
        //trace4(i,sum,AC[i],DEF[i]);
        if(sum == m)
            criminal.insert(i);
    }
    int no_of_criminals = criminal.size();
    //trace1(no_of_criminals);
    FOR(i,1,n)
    {
        if( arr[i] < 0 )//justified
        {
            if(  criminal.count( abs(arr[i]) ) > 0 )
            {   
                if(no_of_criminals > 1)
                    cout << "Not defined\n";
                else
                    cout << "Lie\n";
            }
            else
                cout << "Truth\n";
        }
        else//accused
        {
            if(  criminal.count( abs(arr[i]) ) > 0 )
            {   
                if(no_of_criminals > 1)
                    cout << "Not defined\n";
                else
                    cout << "Truth\n";
            }
            else
                cout << "Lie\n";   
        }
    }

    return 0;
}