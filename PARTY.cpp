#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define gc getchar_unlocked
#define rep(i,n) for(int i=0;i<n;i++)
#define repe(i,n) for(int i=0;i<=n;i++)
#define MAXN 110
using namespace std;
#define MAX(a,b)  ((a) > (b) ? (a) : (b))
void scanint(long long int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int main()
{
    int n,s;
    while(1){
    scanf("%d%d",&s,&n);
    if(s==0 && n==0)
        break;
    long long wt[MAXN],val[MAXN];
    rep(i,n)
    {
    scanint(wt[i]);
    scanint(val[i]);
    }
    long long  K[MAXN][510];
    repe(i,n)
    {
        repe(w,s)
        {
            if(i==0 || w==0)
            {
                K[i][w]=0;
            }
            else if((w>=wt[i-1]) && (K[i-1][w])<(val[i-1]+K[i-1][w-wt[i-1]]))
    {
        K[i][w]=(val[i-1]+K[i-1][w-wt[i-1]]);
    }
            else
            {
                K[i][w]=K[i-1][w];
            }
        }
    }
  int j = s;
    while(K[n][j-1] == K[n][j]) {
        j--;
    }
    printf("%d %lld\n",j,K[n][s]);
}
    return 0;
}
