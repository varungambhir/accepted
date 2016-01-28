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
#define MAXN 1000000
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
{   int t,rem,count;
    ll n;
    scanf("%d",&t);
    while(t--)
    {
        scanint(n);
        count=0;
        while(n)
        {
        rem=n%5;
        if(!(n%5))
            n=(n/5)-1;
        else
            n/=5;
        switch(rem)
        {
            case 0: a[count++]='u';
            break;
            case 1:a[count++]='m';
            break;
            case 2:a[count++]='a';
            break;
            case 3:a[count++]='n';
            break;
            default:a[count++]='k';
            break;
        }
    }
    for (int i = count-1; i>= 0; --i)
    printf("%c",a[i]);
    printf("\n");
    }
    return 0;
}
