#include <cstdio>
#include <cstring>
#include <iostream>

#define gc getchar_unlocked
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
void calc(int num)
{
    char result[1000];
    char r;
    int remainder,i=0;
    while(num!=0)
    {
        remainder=num%(-2);
        num=num/(-2);
        if(remainder<0)
        {
            remainder+=2;
            num+=1;
        }
        r=remainder+'0';
        result[i++]=r;
    }
    result[i]='\0';
    int len=i;
    i=0;
    len--;
while(i<len)
{
    result[i]^=result[len]^=result[i]^=result[len];
    i++;
    len--;
}
    puts(result);
}

int main()
{
    int t;
    char result[1000];
    scanint(t);
    if(t==0)
        printf("0\n");
    else
    {
        calc(t);
    }
    return 0;
}
