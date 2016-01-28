#include <bits/stdc++.h>
#define ll long long int
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
const int N = 22 ;
int g[N][N], i, j, a, b, c, tot_dist[N], mx;
int ans, n;

void dfs(int u)
{
	for(int i=1;i<=n;i++)
	{
		if(i!=u && g[u][i]!=INF && tot_dist[i]==INF)
		{
			tot_dist[i]=tot_dist[u]+g[u][i];
			dfs(i);
		}
	}
}

int main()
{
	
}