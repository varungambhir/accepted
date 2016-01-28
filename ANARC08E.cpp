#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <stack>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
typedef unsigned long long int ull;
#define gc getchar_unlocked
#define FOR(i,n) for(int i=0;i<n;i++)
#define abs(x) ((x)<0 ? -(x) : (x))
#define MAXN 100010
//#define SPEEDY ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
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
void scanintll(long long int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
long long permut(long long n,long long k)
{
    long long result;
    if(k>n)
        {
            result=n;
            n=k;
            k=result;
        }
    if(k*2 > n)
        k=n-k;
    if(!k)
        return 1;
    result=n;
    for (int i = 2; i <=k ; ++i)
    {
        result*=(n-i+1);
        result/=i;
    }
return result;
}
int main()
{
    long long sum,m,n;
    while(1)
    {
        scanintll(m);
        scanintll(n);
        if(m==-1)
            break;
        if(m==0 && n==0)
        printf("0+0!=0\n");
        else{
        sum=permut(m+n,n);
        if(sum==(m+n))
        printf("%lld+%lld=%lld\n",m,n,sum);
        else
        printf("%lld+%lld!=%lld\n",m,n,(m+n));
            }
    }

	return 0;
}

