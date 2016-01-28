#include<cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	int a[1000];
    	int n,i,j,temp,d=1,x;
        scanf("%d",&n);
        a[0]=1;  
        int carry=0;
        for(i=1;i<=n;i++)
        {
        	for(j=0;j<d;j++)
            {
               x=a[j]*i+carry;
               a[j]=x%10; 
			   carry=x/10;
            }
             while(carry)
             { 
               a[d++]=carry%10;
               carry/=10;
             }
       }
    	for(--d;d>=0;d--)
        	printf("%d",a[d]);
        printf("\n");
    }
    return 0;
}
