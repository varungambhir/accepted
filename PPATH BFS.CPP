#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FF(i,a,n) for(i=(a);i<(n);++i)
#define REP(i,a,n) for(i=(a);i<=(n);++i)
#define V(x) vector<x>
#define Sd(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define all(c) c.begin(), c.end()
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define repstl(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define matrix vector< vector<ll> >
#define PI acos(-1.0)
#define EPS 1e-9
#define F1 first
#define S2 second
#define Lf 2*r
#define Rg 2*r+1
//vector< vector<int> >Matrix(N, vector<int>(M,0));
#define gc getchar_unlocked
#define MAXNN 100001
#define mod 1e9+7

inline void inputfile() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
}
inline void cpp_input()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);}
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

bool prime[MAXNN]={0};//prime
bool visited[MAXNN];
int dis[MAXNN];
char num[10];

void sieve()
{

    for(int i=2;i*i<=MAXNN;i++)
    {
        for(int j=i*i;j<MAXNN;j=j+i)
        {
            prime[j]=true;//composite
        }
    }
return;
}

int bfs(int a,int b)
{
    int u,i,j,temp;
    M(visited,false);
    
    FF(i,0,MAXNN)
    dis[i]=-1;

    dis[a]=0;
    queue<int> q;
    q.push(a);
    visited[a]=true;

    while(!q.empty())
    {
        u=q.front();
        q.pop();
        sprintf(num,"%d",u);

        F(i,0,4)
        {
            REP(j,0,9)
            {
                if(i==0 && j==0)
                continue;
                
                num[i] = j + '0';
                temp=atoi(num);

                if(!visited[temp] && !prime[temp] && temp!=u)
                {
                    q.push(temp);
                    visited[temp] = true;
                    dis[temp] = dis[u] + 1;

                    if(temp==b)
                        return dis[b];
                }

            }
            sprintf(num,"%d",u);
        }

    }

return dis[b];
}

int main()
{
    inputfile();
    sieve();
    int di,t,a,b;
    scanint(t);
    while(t--)
    {
        scanint(a);scanint(b);
        if(a==b)
        {
            printf("0\n");
            continue;
        }

         di = bfs(a,b);
        if(di==-1)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("%d\n",di);
        }

    }
    return 0;
}
