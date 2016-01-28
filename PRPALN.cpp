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
typedef long long int ll;
#define gc getchar_unlocked
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAXN 10000010
using namespace std;
char s[1000010];
int l,h;
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
bool istotalpalindrome(char str[])
{
while(h>l)
{
    if(str[l++] != str[h--])
        return false;
}
return true;
}
bool issubpalin(char str[],int li,int hi)
{
while(hi>li)
{
    if(str[li++] != str[hi--])
        return false;
}
return true;
}
int main()
{
 int t;
 scanint(t);
 while(t--)
 {
    gets(s);
    l=0;
    h=strlen(s)-1;
    bool totalcheck=istotalpalindrome(s);
    if(totalcheck==true)
    {
        printf("YES\n");
        continue;
    }
    l--;
    ++h;
    if( issubpalin(s,l+1,h)==true || issubpalin(s,l,h-1) ==true)
    printf("YES\n");
    else
        printf("NO\n");
 } 
  return 0;
} 
