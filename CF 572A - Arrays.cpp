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

int main(int argc, char const *argv[])
{
	BOOST;
	//INPFILE;
	int a,b,k,m;
	cin>>a>>b>>k>>m;
	std::vector<int> av,bv;
	int x;
	FOR(i,0,a)
	{
		cin>>x;
		av.pb(x);
	}
	FOR(i,0,b)
	{
		cin>>x;
		bv.pb(x);
	}
	if(av[k-1] < bv[b-m])
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}

