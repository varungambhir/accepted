#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <climits>
 
using namespace std;
 
const int limit = 100000;
int *primes = (int*)malloc(limit*sizeof(int));
 
int cal_prime()
{
	int *isPrime = (int*)malloc(limit*sizeof(int));
	for(int i = 3; i <= limit; i += 2)
	{
		isPrime[i] = 1;
	}
	const int end = (int)sqrt(limit);
	for (int i = 3; i <= end; i += 2)
	{
		if(isPrime[i])
		{
			for (int composite = 3; i*composite <= limit; composite += 2)
			isPrime[i*composite] = 0;
		}
	}
 
	int i, j;
	for ( i = 1, j = 3; j <= limit; j += 2 )
	{
		if ( isPrime[j] )
		{
			primes[i] = j;
			i++;
		}
	}
	primes[0] = 2;
	return i-1;
}
 
int main()
{
	int i, j, k, l, ind, t, m;
	long long ans, n;
	
	for(i=0; i<100000; i++)
		primes[i] = INT_MAX;
	
	ind = cal_prime();
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld %d", &n, &k);
		ans = 0;
		if(k == 0)
		{
			ans += (n*(n-1))/2;
			printf("%lld\n", ans);
			continue;
		}
		else
		{
			j = 0;
			i = k-1;
			while(primes[i] <= n)
			{
				m = n - primes[i] + 1;
				if(j == 0)
					ans += m;
				else
					ans += m*(primes[j] - primes[j-1]);
				
				i++, j++;
			}
			//ans += (n - primes[i] + 1)*(primes[j] - primes[j-1]);
			printf("%lld\n", ans);
		}
	}
	return 0;
} 