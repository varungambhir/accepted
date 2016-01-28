#include<iostream>
#include<cstdio>
#include<cmath>
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
	int sumele,num,den,n,count,i,t;
	scanint(t);
	float root;
	while(t--)
	{
		scanint(n);
		root=pow(1+8*n,0.5);
		count=(int)floor((-1+root)/2.0);
if((root-(int)root)==0.0)
		{
			if(count%2)
				printf("TERM %d IS 1/%d\n",n,count);
			else
			printf("TERM %d IS %d/1\n",n,count);
		}
else
{		sumele=(count*(count+1))/2;	
		count++;
		num=den=count;
		i=n-sumele-1;
		if(count%2==1)
		{	den=1;
			num-=i;
			den+=i;
		}
		else
		{
			num=1;
			num+=i;
			den-=i;
		}
printf("TERM %d IS %d/%d\n",n,num,den);
}
	}
	return 0;
}