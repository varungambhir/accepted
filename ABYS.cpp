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
#define MAXN 100010
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

long long stack[10010];
static int index=-1;

ll pop(ll stack[])
{
    return(stack[index--]);
}

void push(ll stack[],ll temp)
{
    stack[++index]=temp;
    return;
}

void add(ll stack[])
{
ll temp = pop(stack);
temp+=pop(stack);
push(stack,temp);
return;
}

int main()
{   int t,i,j,k,num;
    scanint(t);
    while(t)
    {   
        gets(a);
        if(strlen(a)==0)
        continue;
        else
        t--;
        index=-1;
        for (i = 0;a[i]!='='; ++i)
        

    }
    return 0;
}