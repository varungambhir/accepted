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

int main()
{
int u,d,f,h;
while(scanf("%d %d %d %d",&h,&u,&d,&f),h||u||d||f)
{
    double currU=u;
    double distMin=u*(f/100.0);
    double currH=0;
    int currDay=0;

    do{
        currDay++;

        currH=currH+currU;

        if(currH>h)
        {
            printf("success on day ");
            break;
        }
        currH-=d;
        if(currH<0)
        {
            printf("failure on day ");
            break;
        }
        currU-=distMin;
        if(currU<0)
            currU=0;
      }while(true);

      printf("%d\n",currDay);
}
return 0;
}
