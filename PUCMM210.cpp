#include<iostream>
#include<cstdio>
#define gc getchar_unlocked
#define MOD 1000000003
void scanint(long long int &x)
{
    register long long int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{
	long long int n,temp,i,t,sum[1000010];
	sum[0]=temp=0;
	for (i = 1;i<1000010; ++i)
	{
		temp=(temp+i*i*i)%MOD;
		sum[i]=(sum[i-1]+temp)%MOD;
	}
	scanint(t);
	while(t--)
	{
		scanint(n);
		printf("%lld\n",sum[n]);
	}
	return 0;
}
