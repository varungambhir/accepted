#include<iostream>
#include<cstdio>
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{	int n;
	scanint(n);
	while(n!=0)
	{	printf("%d\n",(n*(n+1)*(2*n+1)/6));
		scanint(n);
	}
	return 0;
}
