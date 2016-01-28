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
#define MAXN 63
using namespace std;
typedef long long  int ll;
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
char str[MAXN];
int alpha[26];
int main()
{int flag;
while(1){
gets(str);
if(!(strcmp(str,"END")))
break;
else{
flag=0;
for(int i=0;i<26;i++)
alpha[i]=1;
for(int i=0;str[i]!='\0';i++)
{
if(str[i]==' ')
continue;
if(str[i]>='A' && str[i]<='Z')
    {
    if(alpha[str[i]-'A']==0)
        {
            flag=1;
            break;
        }
        else alpha[str[i]-'A']--;
    }
}
if(flag==0)
puts(str);

    }
}
return 0;
}

