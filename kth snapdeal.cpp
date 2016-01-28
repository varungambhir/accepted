#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%lld",&x)
#define pb push_back
#define F first
#define S second
#define L 2*node
#define R 2*node+1
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
inline void INPFILE(){
#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
#endif;
}
#define MAX 200010
#define MOD 1000000007

ll a[1000000];

int main()
{
	freopen("input.in","r",stdin);
	ll type,n,q,x,k;
	SD(n);SD(q);
	FOR(i,0,n)
	{
		SD(a[i]);
	}
	while(q--)
	{
		SD(x);SD(k);SD(type);
		ll m = lower_bound(a,a+n,x) - a;

		//debug(m);
		if(type==1)
		{
			if(a[m]>x)
			;
			m -= k;
		}
		else
		{
			if(a[m]>x)
				m--;
			m += k;
		}
		if(m>=n || m<0)
			printf("-1\n");
		else
			printf("%lld\n",a[m]);
	}

	return 0;
}
