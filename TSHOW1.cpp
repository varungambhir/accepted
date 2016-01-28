#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define gc getchar_unlocked
#define MAXN 100000
using namespace std;
#define MAX(a,b)  ((a) > (b) ? (a) : (b))
typedef long long int ll;
void scanint(ll &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
char a[MAXN];
int main()
{
    int t;
    ll num,temp,n,i,j,ans,k,rem;
    scanf("%d",&t);
    while(t--)
    {
        scanint(num);
        temp=n=0;
        while(temp<num)
        {   n++;
            temp=pow(2,n+1)-2;
        }
        temp=pow(2,n)-2;
        ans=num-temp-1;
        k=-1;
        while(ans>0)
        {   rem=ans%2;
            a[++k]=rem+'0';
            ans/=2;
        }
        j=n-k-1;//n-(k+1)
        for(i=1;i<=j;i++)
            printf("5");
        for (i=k;i>=0;i--)
        {
            if(a[i]=='0')
                printf("5");
            else
                printf("6");
        }
        printf("\n");
    }
    return 0;
}
