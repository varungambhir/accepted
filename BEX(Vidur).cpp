#include <cstdio>
#define gc getchar_unlocked
#define pc putchar_unlocked
/*
#define si(n) scanf("%d",&n)
#define ss(str) scanf("%s",str)
#define pi(n) printf("%d ",n)
#define ps(str) printf("%s\n",str)
*/
 
inline void si(int &x)
{
	register int c = gc();
	x=0;
	int neg=0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
	if(neg) x=-x;
}
 
inline void ss(char *str)
{
	register char c = 0;
	register int i = 0;
	while (c<33)
		c = gc();
	while (c!='\n')
	{
		str[i] = c;
		c=gc();
		i++;
	}
	str[i]='\0';
}
 
inline void pi(int n)
{
	int i=0;
	char ch[25];
	if(n<=0) 
		if(n==0) pc('0');		
		else pc('-'),n=n*-1;
	while(n>0) 
		ch[i]=(n%10)+'0',n=n/10,i++;
	while(i>0)
		pc(ch[i-1]),i--;
	pc(' ');
}
 
inline void ps(char str[])
{
	int i=0;
	while((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
		pc(str[i]),i++;
	pc('\n');
}
 
struct stack
{
	int x;
	char name[20];
	int min;
};
 
stack s[1000001];
 
int main()
{
	int n,x,top=-1;
	char str[20];
	si(n);
	while (n--)
	{
		si(x);
		if(x==0)
			ss(str);
		else if(x!=-1)
		{
			if(top==-1)
			{
				++top;
				s[top].x=x;
				ss(s[top].name);
				s[top].min=top;
			}
			else
			{
				int mn=s[top].min;
				if(x<=s[mn].x)
					mn=top+1;
				++top;
				ss(s[top].name);
				s[top].x=x;
				s[top].min=mn;
			}
		}
		else
		{
			int mn=s[top].min;
			int cnt=top-mn;
			pi(cnt);
			ps(s[mn].name);
			top=mn-1;
		}
	}
	return 0;
} 