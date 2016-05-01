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
int n,m,k;

vector< vector<pair<int,int> > > V;

int visited[310][310] = {0};

void print();

int main(int argc, char const *argv[])
{
    BOOST;
    cin >> n >> m >> k;
        std::vector<pair<int,int> > v;
        if(n == 3 && m == 3 && k == 3)
        {
            FOR(i,0,2)
            {
                cout << 3 << " ";

                FOR(j,0,2)
                cout << i+1 << " " << j+1<< " ";

                cout<<endl;
            }
            return 0;
        }

        int x , y , direc;
        x = y = 0;
        direc = 1;

        v.push_back(make_pair(x+1,y+1));

        while(true)
        {
            y = y + direc;

            if(y == m)
            {
                direc *= -1;
                y = m-1;
                x++;
            }

            if(y == -1)
            {
                direc *= -1;
                y = 0;
                x++;
            }

            if(x == n)
                break;

            v.push_back(mp(x+1,y+1));
        }

        FOR(i,0,k-2)
        {
            cout << "2 ";
            cout << v[2*i].first << " " << v[2*i].second << " ";
            cout << v[2*i+1].first << " " << v[2*i+1].second << "\n";
        }

        cout << m*n - 2*(k-1) << " ";
        FOR(i,(2*(k-1)), m*n-1 )
        {
            cout << v[i].first << " " << v[i].second << " ";
        }
        cout << endl;
        return 0;
    }

void print()
{
    repstl(V)
    {
        int s = (*it).size();
        cout << s << " ";
        
        FOR(i,0,s-1)
        cout << (*it)[i].F << " " << (*it)[i].S << " ";

        cout << endl;
    }
}