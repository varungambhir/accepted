#include<iostream>
#include<cstdio>
#define gc getchar_unlocked
void scanint(long long int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int isSUM(long long int n)
{
	long long int sum = 0, temp = n;
    while(n > 0)
    {
        sum += n%10;
        n = n / 10;
    }
    if(temp % sum == 0)
    {
        return 1;

    }

    return 0;
}
int main()
{
	int t;
	long long int n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanint(n);
		for(i = n ; ;++i)
        {
            if( isSUM(i)==1)
            {
                printf("%lld\n", i);
                break;
            }
        }
	}
	return 0;
}
