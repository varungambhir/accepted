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

#define MAXN 10000010
#define MOD 1000000007

int vis[555] = {0};
set<int> G[555];

char s[555];
set<int> a,b, c;

inline void test()
{
    #ifndef ONLINE_JUDGE
    cout << "b :"; 
    repstl(b)
    cout << *it <<" ";
    cout << "a :"; 
    repstl(a)
    cout << *it <<" ";
    cout << "c :"; 
    repstl(c)
    cout << *it <<" ";
    #endif
    return;
    
}
void dfs(int i,int mark = 2)
{
    if(vis[i])
        return;
    vis[i] = mark;
    
    if(mark == 2)
        a.insert(i);
    else if(mark == 3)
        c.insert(i);

    repstl(G[i])
    {
        if(!vis[*it])
        {
            dfs(*it,mark);
        }
    }
}   

int main(int argc, char const *argv[])
{
    BOOST;
    int u,v,n,m;
    cin >> n >> m;

    FOR(i,1,m)
    {
        cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }

    FOR(i,1,n)
    {
        if(G[i].size() == n-1)
        {
            vis[i] = 1;
            b.insert(i);
        }
    }
    bool ch = 0; 
    if(!b.empty())
    FOR(i,1,n)
    {
        if(vis[i] == 1)
        {
            repstl(G[i])
            {   
                    if(vis[*it]) 
                        continue;
                    a.insert(*it);
                    dfs(*it,2);
                    ch = 1;
                    break;
            }
        }
        if(ch)
            break;
    }
    else
    {
        a.insert(1);
        dfs(1,2);
    }

    ch = 0; 
    FOR(i,1,n)
    {
        if(!vis[i])
        {
            c.insert(i);
            vis[i] = 3;
        }
    }

    bool chk = 0;
    FOR(i,1,n)
    {
        FOR(j,i+1,n)
        {
            if(vis[i] == 2 && vis[j] == 2)
            {
                if(G[i].find(j) == G[i].end())
                {
                    chk = 1;
                    break;
                }
            }
            else if(vis[i] == 3 && vis[j] == 3)
            {
             if(G[i].find(j) == G[i].end())
                {
                    chk = 1;
                    break;
                }   
            }
            else if(vis[i] == 2 && vis[j] == 3 || vis[i]==3 && vis[j]==2)
            {
                if(G[i].find(j) != G[i].end())
                {
                    chk = 1;
                    break;
                }   
            }
        }
    }

    //test();

    if(chk)
    {
        cout << "No\n";
        return 0;
    }
    else
    {
        cout<<"Yes\n";
        s[n] = '\0';
        repstl(a)
            s[*it-1] = 'a';  
        repstl(b)
            s[*it-1] = 'b';  
        repstl(c)
            s[*it-1] = 'c';  
        cout << s << "\n";
           
    }



    return 0;
}