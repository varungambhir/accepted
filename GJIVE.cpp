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
int main()
{	int sum1,sum2,a[10],k;
	for (int i = 0; i < 10; ++i)
	{
		scanint(a[i]);
	}
	sum1=sum2=k=0;
	for (int i = 0; i < 10; ++i)
	{
		if((sum1+a[i])<=100)
		sum1+=a[i];
		else
		{	k++;
			sum2=sum1+a[i];
			break;
		}
	}
	if(!k)//k==0
	{
		printf("%d\n",sum1);
	}
	else if(100-sum1==sum2-100)
	{
		printf("%d\n", sum2);
	}
	else if (100-sum1<sum2-100)//sum1 is closer to 100
	{
		printf("%d\n",sum1);
	}
	else
		printf("%d\n",sum2);
	return 0;
}
