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

const map<char, array<bool, 4>> token =
{
    {'+', {1, 1, 1, 1}},
    {'-', {0, 1, 0, 1}},
    {'|', {1, 0, 1, 0}},
    {'^', {1, 0, 0, 0}},
    {'>', {0, 1, 0, 0}},
    {'<', {0, 0, 0, 1}},
    {'v', {0, 0, 1, 0}},
    {'L', {1, 1, 1, 0}},
    {'R', {1, 0, 1, 1}},
    {'U', {0, 1, 1, 1}},
    {'D', {1, 1, 0, 1}},
    {'*', {0, 0, 0, 0}}
};

const array<int, 4> dx = {0,1,0,-1};
const array<int, 4> dy = {-1,0,1,0};

bool ok(char from, char  to, int rotate, int dir)
{
    int opposite  = (dir+2+4)%4;
    // from rotateed direction gate open from both my end and the 'at' end
    return token.at(from)[(dir-rotate+4)%4] && token.at(to)[(opposite-rotate+4)%4];
}

bool seen[1000][1000][4];
//http://codeforces.com/contest/676/problem/D
//tuple
int main(int argc, char const *argv[])
{   
    BOOST;

    int N,M;
    cin >> N >> M;
    std::vector<string> grid(N);
    FOR(i,0,N-1)
    cin >> grid[i];

    int xT,yT;
    cin >> yT >> xT;
    xT--; yT--;

    int xM,yM;
    cin >> yM >> xM;
    xM--; yM--;
    
    queue<tuple<int,int,int,int> > q;
    q.push(make_tuple(xT,yT,0,0));
    seen[xT][yT][0] = true;

    while(!q.empty())
    {
        int x , y ,r , d;
        tie(x,y,r,d) = q.front();
        q.pop();

        if(x == xM && y == yM)
        {
            cout << d << endl;
            return 0;
        }

        vector<tuple<int,int,int,int> > options;
        options.push_back(make_tuple(x,y,(r+1)%4, d+1));

        for(int dir = 0; dir<4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(!(0 <= nx && nx < M && 0<=ny && ny < N))
                continue;
            if(ok(grid[y][x],grid[ny][nx],r, dir))
                options.push_back(make_tuple(nx,ny,r,d+1));
        }

        for(auto &state: options)
        {
            int x, y ,r , d;
            tie(x,y,r,d) = state;

            if(seen[x][y][r])
                continue;
            else
                seen[x][y][r] = true;

            q.push(make_tuple(x,y,r,d));
        }

    }

    cout << "-1\n";
    return 0;
}