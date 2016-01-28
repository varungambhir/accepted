#include <cstdio>
#include <cstring>

void rev(char s[],int l)
{
	int i=0;
	l--;
	char temp;
	while(i<l)
	{
		temp=s[i];
		s[i]=s[l];
		s[l]=temp;
		i++;
		l--;
	}
}

void division(char s[],int l)
{
	int rem=0,i,flag=0;
	for (i=0;i<l;i++)
	{
		rem=rem*10+(s[i]-'0');
		if((rem/2)!=0 || flag==1)
		{
			printf("%d",rem/2);
			flag=1;
		}
		rem=rem%2;
	}
	printf("\n");
}

int main()
{
	int t=10;
	while (t--)
	{
		char a[256]="\0",b[256]="\0";
		char sum[256]="\0",diff[256]="\0",zero[256]="\0";
		int n=0,m=0;
		int i,j;
		scanf("%s",a);
		scanf("%s",b);
		
		/*Making length equal*/
		int la=strlen(a),lb=strlen(b);
		for (i=0;i<(la-lb);i++)
			zero[i]='0';
		strcat(zero,b);
		strcpy(b,zero);
		lb=strlen(b);
		
		/* addition */
		int lsum=0, carry=0;
		for (i=la-1,j=lb-1;j>=0;i--,j--)
		{
			n=a[i]-'0';
			m=b[j]-'0';
			sum[lsum++]=(n+m+carry)%10 + '0';
			carry=(n+m+carry)/10;
		}
		if (carry)
		{
			sum[lsum++]=carry%10 + '0';
			carry/=10;
		}
		sum[lsum]='\0';
		rev(sum,lsum);
		division(sum,lsum);
		
		/* subtraction */
		int ldiff=0;
		n=0;
		for(i=la-1;i>=0;i--)
        {
            if(a[i]>=b[i])
                    diff[ldiff++]=a[i]-b[i]+'0';
            else
            {
                a[i-1]=a[i-1]-1;
                n=(a[i]-'0')+10-(b[i]-'0');
                diff[ldiff++]=n+'0';
            }
        }
		diff[ldiff]='\0';
		rev(diff,ldiff);
		division(diff,ldiff);
	}
	return 0;
}
