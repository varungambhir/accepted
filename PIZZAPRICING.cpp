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
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define gc getchar_unlocked
#define PI 3.1415926
using namespace std;
typedef long long  int ll;
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

int main()
{
int n,p[11],d[11],mini,c=1;
float ans[11],min;
while(1)
{
scanint(n);
if(!n)
break;
for(int i=0;i<n;i++)
    {
    scanint(d[i]);
    scanint(p[i]);
    ans[i]=p[i]/( PI*d[i]*d[i]);
    }
min=ans[0];
mini=0;
for(int i=1;i<n;i++)
if(ans[i]<min)
{
mini=i;
min=ans[i];
}
printf("Menu %d: %d\n",c++,d[mini]);
}
return 0;
}


