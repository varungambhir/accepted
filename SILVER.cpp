#include <cstdio>
int main()
{
	int n,count;
	while(scanf("%d",&n)==1)
	{
		count=0;
		while(n>1)//as final count-1 will be for 1
		{
			count++;
			n/=2;
		}
		printf("%d\n", count);
	}
	return 0;
}