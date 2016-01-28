#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define F first
#define S second
#define L 2*node
#define R 2*node+1
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define INPFILE freopen("input.in","r",stdin)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define MAX 200010
#define MOD 1000000007

//credit's Nellex

string s[5];

int dp[110][5][50];
bool flag;

bool check(int x,int y)
{
	if(y>3 || y< 1)
		return 0;

	FOR(i,x,x+2+1)
	{
		if(i>=s[y].size())
			return 1;
		else if(s[y][i]!='.')
			return 0;
	}

	return 1;

}

bool rec(int x,int y,bool z)
{
	if(flag)
		return 1;

	if(y>3 || y< 1)
		return 0;

	if(dp[x][y][z] != -1)
		return dp[x][y][z];

	if(z)
		return rec(x+1,y,!z);


	if(x>=s[y].size())
		{
			flag = 1;
			return 1;
		}

	if(s[y][x] != '.')
		return 0;

	dp[x][y][z] = 0;

	if( check(x,y) )
	{
		dp[x][y][z] += rec(x+2,y,!z);
	}
	if( check(x,y-1) )
	{
		dp[x][y][z] += rec(x+2,y-1,!z);
	}
	if( check(x,y+1) )
	{
		dp[x][y][z] += rec(x+2,y+1,!z);
	}

	return dp[x][y][z];
}

int main(int argc, char const *argv[])
{
	//INPFILE;
	BOOST;
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		memset(dp,-1,sizeof(dp));
		flag = 0;

		FOR(i,1,3+1)
		{
			cin>>s[i];
		}
		int ss=0;

		FOR(i,1,3+1)
		if(s[i][0]=='s')
			ss = i;

        if(ss==0)
            cout<<"ERRPR\n";

		if(s[ss][1]!='.')
		{
			cout<<"NO"<<endl;
			continue;
		}

		if(rec(0,ss,1))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
