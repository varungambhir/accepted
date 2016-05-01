#include <bits/stdc++.h>
typedef unsigned long long int ull;
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
void scanintll(unsigned long long int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
struct act
{
    int s,f;//start finish
}s1[MAXN];

bool val(act a,act b)
{
    if(a.f==b.f)
        return a.s<b.s;

    return a.f<b.f;
}
int main()
{
    int t,n,end,count,i;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        end=-1;
        scanf("%d",&n);
        for ( i = 0; i < n; ++i)
        {
            scanint(s1[i].s);
            scanint(s1[i].f);
        }
        std::sort(s1,s1+n,val);
        for (i = 0; i < n; ++i)
            {
                if(s1[i].s>=end)
                {
                    count++;
                    end=s1[i].f;
                }
            }    
            printf("%d\n",count);
    } 
  return 0;
}
