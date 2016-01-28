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
#define MAXN 10010
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
  //std::ios_base::sync_with_stdio(false);
  //char* fmt = "%[^\n]%*c";
  string a;
    long long int j,i,l;
  while(getline (cin,a))
  {
    l=-1;
    for(i=0;a[i]!=NULL;i++)
    {
      if(a[i]==' ')
      {
        for(j=i-1;j>l;j--)
        {
          printf("%c",a[j]);
        }
        printf(" ");
        l=i;
      }
    }
    for (--i; i>l ; --i)
    {
      printf("%c",a[i]);
    }
    printf("\n");
  }
    return 0;
}
