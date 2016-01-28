#include<cstring>
#include<cstdio>
#define MOD 1000000007
int main()
{
	char a[100002];
	short t;
	scanf("%d",&t);
	int i,level,l;
	unsigned long long int num;
	while(t--)
	{
		level=0;
		fflush(stdin);
		scanf("%s",&a);
		for(i=0;a[i]!='\0';i++);
		l=i;
		for(i=0;i<l;i++)
		{	level++;
			if(level==1)
			{
				if(a[i]=='l')
					num=2;
				else num=4;
			}
			else{
					if(level%2)//next level
					{
 						if(a[i]=='l')
 						{
 							num=((2*(num%MOD))%MOD);
 						}
 						else
 						{
 							num=((2*(num)%MOD)%MOD+2)%MOD;
 						}
					}
					else{
							if(a[i]=='l')
							{
								num=((2*(num%MOD))%MOD-1)%MOD;
							}
							else{
								num=((2*(num%MOD))%MOD+1)%MOD;
								}
						}
				}
		}
	printf("%llu\n",num);
	}
	return 0;
}
