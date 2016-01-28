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
typedef long long int ll;
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

char a[22];
ill fact[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000,51090942171709440000};
void swap(char*x,char*y)
{
    char w;
    w=*x;
    *x=*y;
    *y=w;
}

void permute(char *line,ill target,int len)
{
    //target permutation number
    //len lenght of str
    //d difference
    sort(a,a+len);
    if(target==0)
        return;
    for(d=0,i=0;i<=len && fact[len-1]*i<=target;++i)
        d=fact[len-1]*i;
    swap(line,line+i-1);
    permute(line+1,target-d,len-1);
    
}
int main()
{
int t;
scanint(t);
while(t--)
{
    long long int n;
    gets(a);
    scanintll(n);
    int leng=strlen(a);
    permute(a,n,leng);
    puts(line);
}
return 0;
}
