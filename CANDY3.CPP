#include<cstdio>
#include<iostream>
#define gc getchar_unlocked
void scanint(long long int &x)
{
    register long long int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{	
	long long sum,n,i,t,b;
	scanint(t);
	while(t--)
	{	sum=0;
		scanint(n);
		//(a+b)%m = (a%m + b%m)%m
		for (i = 0; i < n; ++i)
		{	scanint(b);
			sum=(sum%n+b%n)%n;
		}
	if(sum==0)	
	printf("YES\n");
else
	printf("NO\n");
	}
	return 0;
}