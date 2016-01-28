#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
#define pb push_back
#define si(x) scanf("%d", &x);
#define sii(x,y) scanf("%d%d", &x, &y);
#define sll(x) scanf("%lld", &x);
#define pi(x) printf("%d\n", x);
#define pll(x) printf("%lld\n", x);
int main()
{
	int t=1;
	while(t--)
	{
		int n, m, k, a, b;
		int board[101][101] = {0};
		scanf("%d%d%d", &n, &m, &k);
		while(k--)
		{
			scanf("%d%d", &a, &b);
			board[a][b] = 1;
		}
		int i, j, moves=0;
		int arr[10001][2];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(board[i][j] == 0)
				{
					arr[moves][0] = i;
					arr[moves++][1] = j;
					while(board[i][j]!=1 && j!=m)
						j++;
				}
			}
		}
		printf("%d\n", moves);
		for(i=0;i<moves;i++)
			printf("%d %d 0\n", xy[i][0], arr[i][1]);	
	}
	return 0;
}

