#include <cstdio>
#include <cstdlib>
#include <iostream>
#include<cstring>
#define gc getchar_unlocked
#define MOD 1000000007
using namespace std;
typedef unsigned long long int ull;
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

 ull fib(ull n){
    /*
    To implement this in O(log n ) time we have to make use of the information given below.

1
2
3
x^n    =    x*x^n-1,    if n is odd

            x^n/2 * x^n/2    if n is even
*/
    
    unsigned long long ans[2][2],fibonacci[2][2]={{1,1},{1,0}},result[2][2]={{1,0},{0,1}};
 
    while(n)
 
    {
 
        if(n%2==1)
 
        {
 
            memset(ans,0,sizeof(ans));
 
                for(int i=0;i<2;i++)
 
                    for(int j=0;j<2;j++)
 
                        for(int k=0;k<2;k++)
 
                            ans[i][j]=(ans[i][j]+result[i][k]*fibonacci[k][j]);
 
                for(int i=0;i<2;i++)
 
                     for(int j=0;j<2;j++)
 
                        result[i][j]=ans[i][j];
 
        }
 
        memset(ans,0,sizeof(ans));
 
        for(int i=0;i<2;i++)
 
            for(int j=0;j<2;j++)
 
                for(int k=0;k<2;k++)
 
                    ans[i][j]=(ans[i][j]+fibonacci[i][k]*fibonacci[k][j]);
 
        for(int i=0;i<2;i++)
 
            for(int j=0;j<2;j++)
 
                fibonacci[i][j]=ans[i][j];
 
        n/=2;
 
    }
 
    return result[0][1];
 
}
int main()
{
    int t,n,m;
    scanint(t);
    ull ans;
    while(t--)
    {
        scanint(n);
        scanint(m);
        ans=(fib(m+2)-fib(n+1))%MOD;
        printf("%llu\n",ans);
    }

    return 0;
}
