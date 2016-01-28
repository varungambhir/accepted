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
#define FOR(i,n) for(int i=0;i<n;i++)
#define repe(i,n) for(int i=0;i<=n;i++)
#define PI 3.1415926
using namespace std;
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
    
 int t;
 float ans;
 while(1){
 scanint(t);
if(!t)
    break;
ans= (t*t)/(4*PI);
printf("%f\n",ans );
}
    return 0;
}
