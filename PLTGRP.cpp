#include<iostream>
#include<cstdio>
#define gc getchar_unlocked
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
int main()
{
int j,loc,n,i,a[100001],d[100001];
scanint(n);
for(i=0;i<n;i++)
scanint(a[i]);
loc=1;
d[0]=a[0];
for(i=1;i<n;i++)
{
    for(j=0;j<loc;j++)
    {
    if(d[j]>a[i])
        {d[j]=a[i];
        break;}
    }
    if(j==loc)
    {d[loc++]=a[i];
    }
}
printf("%d\n",loc);
return 0;
}
