#include<cstdio>
#include<cstdlib>
#include<cmath>
static int table[] = {
    0, 0, 0, 0, 1, 1, 1, 1, 6, 2, 4, 8, 1, 3, 9, 7, 6, 4, 6, 4, 
    5, 5, 5, 5, 6, 6, 6, 6, 1, 7, 9, 3, 6, 8, 4, 2, 1, 9, 1, 9
};

long long int unit_digit(long long int n,long long int a)
{   if(a==0)
    return 1;
    else
    return table[((n%10)<<2)+(a&3)];
}
int main()
{
     long long int a,b,t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        a=unit_digit(a,b);
        printf("%lld\n",a );
    }
    return 0;
}
