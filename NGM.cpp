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
{
	int x;
	scanint(x);
	if(x % 10 == 0){
		printf("2\n");
	}
	else{
		printf("1\n");
		printf("%d\n", x%10);
	}
	return 0;
}
