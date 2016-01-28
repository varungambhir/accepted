#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long  long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define FOR(i,a,n) for(int (i)=(a);(i) < (n); ++(i))
#define FF(i,a,n) for ((i) = (a); (i)<(n);++(i))
#define REP(i,a,n) for ((i) = (a); (i)<=(n);++(i))
#define V(x) vector<x>
#define Sd(x) scanf("%d",&x)
#define all(c) c.begin(),c.end()
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define F first
#define S second
#define PI acos(-1.0)
#define EPS 1e-9
#define Lf 2*r
#define Rg 2*r+1
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define matrix vector< vector<ll> >

inline void inputfile()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	#endif
}
inline void cpp_input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
#define MAX 1e9*2+1
#define mod 1000000007


int main(int argc, char const *argv[])
{
	//inputfile();
	cpp_input();
	int x[100010],h[100010];
	int n,a;
	ll b;
	cin>>n;
	FOR(i,0,n)
	{
		cin>>x[i]>>h[i];
	}
	x[n]=MAX;
	a = 0 , b = -MAX;
	FOR(i,0,n)
	{
		if(b < x[i] - h[i])
		{
			a++;
			b = x[i];
		}
		else if(x[i] + h[i] <x[i+1])
		{
			a++;
			b = x[i] + h[i];
		}
		else
			b = x[i];
	}

	cout<<a;
	return 0;
}
