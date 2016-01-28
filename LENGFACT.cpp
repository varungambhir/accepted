#include<iostream>
#include<cstdio>
#include<cmath>
#define gc getchar_unlocked
#define PI 3.14159265358979323846
void scanint(long long int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{
	int t;
	long long n;
	scanf("%d",&t);
	while(t--)
	{
		scanint(n);
		if(n==1 || n==0)
		printf("1\n");
		else{
		n=ceil((log(2*PI)-2*n+(1+2*n)*log(n))/(log(100)));
		printf("%lld\n",n);
			}
	}
	return 0;
}
