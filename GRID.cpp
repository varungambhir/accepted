#include<iostream>
#include<cstdio>
#include<cstring>
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
    int t,ok,n,ans;
    char RayX[1010][1010],RayY[1010][1010],inp[1010][1010];
    scanint(t);
    while(t--)
    {
        scanint(n);
        fflush(stdin);
        for (int i = 0; i < n; ++i)
        {
          scanf("%s",inp[i]);
        }

      for (int i = 0; i <  n; ++i)
      { ok=1;
        for (int j = n-1; j>=0; --j)
        {
          if(inp[i][j]=='#')
          {
            ok=0;
          }
          RayX[i][j]=ok;
        }
      }

      for (int j = 0; j <  n; ++j)
      { ok=1;
        for (int i = n-1; i>=0; --i)
        {
          if(inp[i][j]=='#')
          {
            ok=0;
          }
          RayY[i][j]=ok;
        }
      }
      ans=0;
      for (int i = 0; i < n; ++i)
      {
        for (int j = 0; j < n; ++j)
        {
        if(RayX[i][j] && RayY[i][j])
          ans++;
        }
      }
     printf("%d\n",ans);
    }
    return 0;
}
