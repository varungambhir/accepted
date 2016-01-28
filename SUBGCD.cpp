#include<iostream>
#include<cstdio>
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int gcd(int a,int b)
{while(b) 
 b ^= a ^= b ^= a %= b;
    return a;}
/*{
    return b==0?a:gcd(b,a%b);
}*/
int main()
{
    int t,x,n,ans;
    scanint(t);
    while(t--)
    {
        scanint(n);
       for (int i = 1; i <= n; ++i)
       {
           scanint(x);
           ans=(i==1)?x:gcd(x,ans);
       }
       if(ans==1)
        printf("%d\n",n);
      else
        printf("-1\n");

    }
    return 0;
}