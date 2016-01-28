#include<cstdio>//VIDUR ANSWER
#define MOD 1000000007
#include<iostream>
using namespace std;

char a[15000]="1";
int d=1;

void rev(int l)
{
	int i=0;
	l--;
	while(i<l)
	{
		a[i]^=a[l]^=a[i]^=a[l];//swapping using XOR
		i++;
		l--;
	}
}

void mult(int n)
{
	int carry=0,i,j,x;
	for(i=n;i>=n-5;i--)
	{
		for(j=0;j<d;j++)
		{
			x=(a[j]-'0')*i+carry;
			a[j]=x%10+'0';
			carry=x/10;
		}
		while(carry)
		{
			a[d++]=carry%10+'0';
			carry/=10;
		}
    }
    a[d]='\0';
    rev(d);
}

void div()
{
	int rem=0,i,flag=0,j=0;
	for (i=0;a[i]!=NULL;i++)
	{
		rem=rem*10+(a[i]-'0');
		if((rem/720)!=0 || flag==1)
		{
			a[j++]=rem/720+'0';
			flag=1;
		}
		rem=rem%720;
	}
	d=j;
	a[d]='\0';
}

void modulo()
{
	long long rem=0,i;
	for (i=0;a[i];i++)
	{
		rem=rem*10+(a[i]-'0');
		rem=rem%MOD;
	}
	printf("%lld\n",rem);
}

int main()
{
	int r;
	scanf("%d",&r);
	if(r<13)
		printf("0\n");
	else if(r<15)
		printf("1\n");
	else
	{
		r=(r-1)/2 - 6;
		mult(r+6);
		div();
		modulo();
	}
	return 0;
}
