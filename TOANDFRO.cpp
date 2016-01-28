#include<iostream>
#include<cstdio>
#include<cstring>
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
	int t,l,i,flag,j;
	scanint(t);
	char a[202];
	while(t!=0)
	{
	 gets(a);
	 for(l=0;a[l]!=NULL;l++);
	for(i=0;i<t;i++)
	{	flag=0;
		for(j=i;j<l;)
		{	
			if(flag==1)
			{
			printf("%c",a[j]);
			flag=2;
			j+=(1+2*i);
			}
			else if(flag==2)
			{
				printf("%c",a[j]);
				flag=1;
				j+=(2*(t-i)-1);
			}
			else if(flag==0)
			{printf("%c",a[i]);
			flag=1;
			j+=(2*(t-i)-1);}
		}
	}
	printf("\n");
	scanint(t);
	}
	return 0;
}
