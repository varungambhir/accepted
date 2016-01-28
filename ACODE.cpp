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
char s[1000000];
ll ans[1000000];
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
 int l,temp;
 while(scanf("%s",s)==1 && strcmp(s,"0")!=0)
 {
    l=strlen(s)-1;
   // cout<<"Leng  "<<l<<endl;
    ans[0]=1;
    ans[1]=0;
    if(l==0)
    {printf("1\n");continue;}

    temp = (s[0]-48)*10 + s[1]-48;
    if(temp==10 || temp==20)
    ans[1]=1;

    else if(temp<27 && temp>0)
        ans[1]=ans[0]+1;

    if(temp>26 && s[1]!='0')
    ans[1]=1;    

    if(ans[1]==0)
    {printf("0\n");continue;}

    if(l<2)
    {
        printf("%lld\n",ans[1]);
    }

    else
    {
  for (int i = 2; i <= l; ++i)
    {
        if(s[i]=='0' && (s[i-1]=='1' || s[i-1]=='2'))
        {
            ans[i]=ans[i-1]=ans[i-2];
        }
        else if(s[i]=='0' && s[i-1]>'2')
        {
            ans[l]=0;
            break;
        }
        else{
        if(s[i-1]=='0')
        {
         ans[i]=ans[i-1];
        }
        else
        {
        temp=(s[i-1]-48)*10 + s[i]-48;
      //  cout<<temp<<"\n";
        if(temp<27 && temp>0)
        {
            ans[i]=ans[i-1]+ans[i-2];
        }
        else
        {
            ans[i]=ans[i-1];
        }
            }
        }
    }  
printf("%lld\n",ans[l]);
        }
}
  return 0;
}
