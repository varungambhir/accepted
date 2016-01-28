#include<iostream>
#include<cstdio>
#include<cstdlib>
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
static int n;

int main()
{
	scanint(n);
	printf("%d\n",sum);
	return 0;
}
