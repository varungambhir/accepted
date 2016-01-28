#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod;
ll calcsum(ll n)
{
	ll ans = n%mod;
	ans = (ans*(2*n+1)%mod)%mod;
	ans = (ans*(n+1)%mod)%mod;
	ll val = ((n%mod)*(n%mod)*3)%mod;
	val = (val+(3*n)%mod)%mod;
	val = (val-1)%mod;
	ans = (ans*val)%mod;
	ans = ans/30;
	return ans;
}
int main()
{
	ll t, n, m, i, j;
	scanf("%lld", &t);
	while(t--)
	{
		ll sum=0;
		scanf("%lld%lld", &n, &m);
		mod = 30*m;
		for(i=1;i<=n;)
		{
			j = i;
			sum = (sum + ((calcsum(n/(n/i)) - calcsum(j-1) + m)*(n/i))%m)%m;
			i = n/(n/i) + 1;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
