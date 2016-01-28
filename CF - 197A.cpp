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
	INPFILE;
	string f,s;
	cin>>f;
	std::vector<int> v;
	FOR(i,0,f.length())
	{
		if(f[i]!='+')
			v.push_back((int)(f[i]-'0'));

	}
	sort(v.begin(),v.end());
	if(v.size()==1)
	{
		cout<<v[0];
	}
	else
	{
		cout<<v[0];
		FOR(i,1,v.size())
		{
			cout<<"+"<<v[i];
		}
	}
	cout<<endl;
	return 0;
}
