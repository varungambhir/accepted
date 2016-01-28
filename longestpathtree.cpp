Longest path in a tree
Given below code is for PTZ07Z spoj or Longest path in a tree spoj.

You can solve this using DFS of applying BFS twice.

For BFS twice 
In first bfs you have to find maximum length of node from root then in second bfs consider that node as root and find maximum distance from that .That will be our answer.

1-> Using DFS.

#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
bool check[MAX]={false};
int total=0;
int dfs(vector<int> v[],int root)
{
    int m,m1=-1,m2=-1;
    check[root]=1;
    for(int i=0;i<v[root].size();i++)
    {
        if(!check[v[root][i]]){
            m = dfs(v,v[root][i]);
            if(m>=m1)
            {
                m2= m1;
                m1 = m;
            }
            else if(m>m2)
                m2=m;
        }
    }
    total = max(total , m1+m2+2);
    return (m1 + 1);
}
int main()
{
    int n,a,b;
    cin>>n;
    vector<int> v[n+9];
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(v,1);
    cout<<total<<endl;
}
1-> Using Double BFS .



#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000
vector < int > g[MAXN + 1];
int maxWt[MAXN + 1];
bool check[MAXN + 1];
void bfs(int n)
{
    queue <pair<int, int> > q;
    q.push(make_pair(n, 0));
    while (!q.empty())
    {
        int root = q.front().first;
        int wt = q.front().second;
        check[root] = true;
        for(int i = 0; i<g[root].size(); i++)
        {
            if (!check[g[root][i]])
            {
                q.push(make_pair(g[root][i], wt + 1));
            }
        }
        maxWt[root] = wt;
        q.pop();
    }
}
int main()
{
    int n,a,b;
    cin>>n;
    vector<pair<int,int> > v[n+9];
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(1);
    int maxRoot = 0;
    for(int i = 1; i<= n; i++)
        maxRoot = maxWt[maxRoot] < maxWt[i] ? i : maxRoot; 
    memset(maxWt, 0, sizeof(maxWt));
    memset(check, 0, sizeof(check));
    bfs(maxRoot);
    maxRoot = 0;
    for(int i = 1; i<= n; i++)
        maxRoot = max(maxRoot, maxWt[i]);
    cout<<maxRoot<<endl;
    return 0;
}