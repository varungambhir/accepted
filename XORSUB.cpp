#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <stack>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
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
int arr[1100],number[1100],check[1100];
int main()
{
    int k,t,n,i,j,ind,in,tmp;
    scanf("%d",&t);
    while(t--)
    {
       scanint(n);
       scanint(k);
       memset(check,0,sizeof(check));
       for ( i = 0; i < n; ++i)
       {
        scanint(arr[i]);
       }
       ind=1;
        number[0]=k;
        check[k]++;
    for ( i = 0; i<n; ++i)
    {
        number[ind++]=arr[i]^k;
        //cout<<" i loop "<<(arr[i]^k)<<" \n";
        check[arr[i]^k]++;
        in=ind;
        for(j=0;j<in;j++)
        {
            tmp=arr[i]^number[j];
            //cout<<"j loop "<<tmp<<"\n";
            if(!check[tmp])
            {
                number[ind++]=tmp;
                check[tmp]++;
            }
        }
    }
    //printf("\n");
    sort(number,number+ind);
    /*for (int i = 0; i < ind; ++i)
    {
        printf("%d\n",number[i]);
    }*/
    printf("%d\n",number[ind-1]);
    
    }

	return 0;
}
