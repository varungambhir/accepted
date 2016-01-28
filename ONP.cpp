#include<cstdio>
#include<cstring>
int comp(char c)
{
	if (c=='^') return 4;
	if (c=='*') return 3;
	if (c=='/') return 3;
	if (c=='+') return 2;
	if (c=='-') return 2;
	if (c=='(') return 1;
}
int main()
{	int c,t,i;
	scanf("%d",&t);
	char a[401],stack[401];
	while(t--)
	{
	c=0;
	scanf("%s",a);
	for(i=0;a[i]!=NULL;i++)
        {
            if(a[i]>=97 && a[i]<=122)
            printf("%c",a[i]);
            else if(a[i]=='(')
            stack[c++]=a[i];
            else if(a[i]==')')
            {
              while(stack[c]!='(')
              printf("%c",stack[c--]);
            }
            else
            {
            while(stack[c--]!='(')
                    {
                    if(comp(a[i])<=comp(stack[c--]))
                    printf("%c",stack[c--]);
                    else {break;}
                    }
                    ++c;
                    stack[c++]=a[i];
            }
        }
    printf("\n");
    }
	return 0;
}
