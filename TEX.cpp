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
char a[10000000];
int main()
{
  //std::ios_base::sync_with_stdio(false);
  //char* fmt = "%[^\n]%*c";
    int leftright=1;
  while(gets(a))
  {
    for (int i = 0; a[i]!='\0' ; ++i)
    {
      if(a[i]==34)//a[i]=='"'
        {
          leftright=(!leftright);
          if(!leftright)
          printf("``");  
          else
            printf("''");
        }
      else
        printf("%c",a[i]);
    }
    printf("\n");

  }
    return 0;
}
