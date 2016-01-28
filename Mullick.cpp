
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second
typedef pair<ll,int> ii;
typedef pair<int,pair<ll,int> > iii;

vector<iii> graph[100005];
bool used[100005];
ll D[100005];

set<ii> S;

void dijkstra(int st)
{
    S.insert(ii(0,st));
    
    ii top;
    int u,v,t,i;
    ll c;
    D[st]=0;
    
    while(!S.empty())
    {
        top = *S.begin();
        S.erase(S.begin());
        c = top.f;
        u = top.s;
        
        
        for(i=0;i<graph[u].size();i++)
        {
            iii x = graph[u][i];
            v = x.f;
            t = x.s.s;
            
            if(D[v]>D[u]+x.s.f)
            {
                if(D[v]!=1e17)
                {
                    S.erase(S.find(ii(D[v],v)));
                    if(used[v])
                        used[v]=0;
                }
                
                D[v]=D[u]+x.s.f;
                S.insert(ii(D[v],v));
                if(t==1)
                    used[v]=1;
            }
            
            else if(D[v]==D[u]+x.s.f && t==0)
            {
                if(D[v]!=1e17)
                {
                    S.erase(S.find(ii(D[v],v)));
                    if(used[v])
                        used[v]=0;
                }
                D[v]=D[u]+x.s.f;
                S.insert(ii(D[v],v));
                used[v]=0;
            }
        }
    }
    
}


int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m,k,i,a,b,y,c;
    cin>>n>>m>>k;
    
    fill(used,used+n+1,0);
    fill(D,D+n+1,1e17);
    
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        graph[a].pb(iii(b,ii(c,0)));
        graph[b].pb(iii(a,ii(c,0)));
    }
    
    for(i=0;i<k;i++)
    {
        cin>>c>>y;
        graph[1].pb(iii(c,ii(y,1)));
        graph[c].pb(iii(1,ii(y,1)));
    }
    
    dijkstra(1);
    
    int r=0;
    for(i=1;i<=n;i++)
    {
        if(used[i])
            r++;
    }
    
    cout<<k-r<<"\n";
    return 0;
}