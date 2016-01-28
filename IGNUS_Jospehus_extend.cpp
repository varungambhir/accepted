#include <bits/stdc++.h>
#define Int long long int
using namespace std;
int main()
{
	Int n, t;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		Int x = 1;
		while (x <= n) {
			x = x*2;
		}
		x = x/2;
		Int ans = 2*(n-x) + 1;
		printf("%lld\n", ans);
	}
	
	return 0;
} 