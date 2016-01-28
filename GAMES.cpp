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
#define inf 1000000000
#define MAXN 2000

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
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int number,frac,i,t,count,flage;
    scanint(t);
    while(t--){
    string s;
    cin>>s;
    number=0;
    count=0;
    flage=0;
    for (i = s.size()-1; i>=0; --i)
    {
        if(s[i]=='.')
        {
            flage=1;
            break;
        }
        else
            count++;
    }
    for (i = 0; i < s.size(); ++i)
    {   
        if(s[i]!='.')
        number=number*10+(s[i]-48);
    }
    frac=1;
    if(flage)
        {
            frac=pow(10,count);
        }
        printf("%d\n",frac/gcd(number,frac));
    }
    return 0;
}