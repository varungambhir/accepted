#include <cstdio>
#include <cstring>
char n[128];
int main()
{
int len,carry,x,temp,i;
while(scanf("%s",n+1)==1)
{
	len=carry=0;
	while(n[++len]);
	//n=n-1
	for (i = len;n[--i]=='0';n[i]='9');
	if(len==2 && n[1]=='1')
	{
		puts("1");
		continue;
	}
	--n[i];
	//n=n*2
	for(i=len;--i;)//n[0] is never accessed
	{
		n[i] = '0' +  (carry = carry + ( n[i] - '0' ) * 2 ) % 10;
		carry/=10;
	} //storing in linear way ; opposite to method in FCTRL2
	if(carry)
	{
		n[0]=carry+'0';
		puts(n);
	}
	else
		puts(n+1);
}
return 0;
}
