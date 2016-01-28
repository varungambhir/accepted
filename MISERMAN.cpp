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
#define MOD 1000000007
#define MAXN 102
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
int min(int x, int y)
{
  return  y + ((x - y) & ((x - y) >>
            (sizeof(int) * CHAR_BIT - 1)));
}
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int smallest(int x, int y, int z){
    return min(x, min(y, z));
}
int grid[MAXN][MAXN];
int arr[MAXN];

int main()
{
        int n,m;
        scanint(n);
        scanint(m);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                 scanint(grid[i][j]);
            }
        }
        for (int j = 1; j < n; ++j)
        {   
          
            for (int i = 0; i < m; ++i)
            {
                if(i==0)
                {
                     grid[j][i]+=smallest(grid[j-1][i],grid[j-1][i+1],grid[j-1][i]);
                }
                else if(i==m-1)
                {
                     grid[j][i]+=smallest(grid[j-1][i],grid[j-1][i-1],grid[j-1][i]);
                }
                else{
                    grid[j][i]+=smallest(grid[j-1][i],grid[j-1][i-1],grid[j-1][i+1]);

                }
            }
        if(j==n-1)
        {
            for (int i = 0; i < m; ++i)
            {
                arr[i]=grid[j][i];
            }
        }
        }
        qsort(arr,m,sizeof(int),compare);
        printf("%d\n",arr[0]);
    return 0;
}
