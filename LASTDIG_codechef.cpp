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
int darr[10]={0, 1, 4, 3, 8, 5, 2, 7, 6, 9};
int d(long long n)
{
    long long temp=n%10;
    if(n>9)
    {
        return (d((n-temp)/10)+d(temp))%10;
    }
    else
        return darr[n];
}
int c(long long n)
{
    if(!(n%10))
    {
        return (45*n/10);
    }
    else
    {
        return (c(n-1)+d(n-1));
    }
}
int main()
{
    int t,sum;
long long a,b,temp;
scanint(t);
while(t--)
{
    scanintll(a);
    scanintll(b);
    if(a>b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    sum=c(b+1)-c(a);
printf("%d\n",sum);
}
return 0;
}
