#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <complex>
using namespace std;
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FF(i,a,n) for(i=(a);i<(n);++i)
#define REP(i,a,n) for(i=(a);i<=(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) ((a)>(b)?(a):(b))
#define gc getchar_unlocked
ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

/* Input from file or online */
void inputfile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}
/* Input opener ends */

#define MAXN 22
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
int powerset[23]={1,2,4,8,16,32,64,128,256,512,
1024,2048,4096,8192,16384,32768,65536,131072,262144,
524288,1048576,2097152,4194304};
long long int arr[22];
int main()
{
       int t;
    scanf("%d",&t);
    
    std::vector<long long int> v;
    std::map<long long int, vector<int> > ma;
    
    while(t--)
    {
    int n,k,nn;
    scanint(n);
    scanint(k);
    ill sum=0;
    for(int i=0;i<n;i++)
    {
        scanintll(arr[i]);
        sum+=arr[i];
        if(arr[i]){
        v.push_back((arr[i]));
        ma[arr[i]].push_back((i));
        }
    }
    

    if(sum%k)
    {
        printf("no\n");
    }
    
    else if(n>=k && sum==0)
    {
        printf("yes\n");
    }
    

    else 
    {
    ill avg=sum/k;
    
    int leng=ma[avg].size();
    
    if(leng)
    {
    
        int temp=leng-1;
        while(temp)
        {
            v.erase(v.begin() + ma[avg][temp--]);
        }
    
    }
    for (int i = 0; i <(k-leng); ++i)
    {


        for (int j=powerset[v.size()] - 1 ;j>=0 ; j--)
        {
            sum=nn=0;
            int number[21]={0};


            for(int ij=0;ij<v.size();ij++)
            {
                if(((j>>ij)&1)!=0)
                    {
                        number[nn++]=ij;
                    }
                sum=sum + ((j>>ij)&1)*v[ij];
            }
            nn--;
            if(sum==avg)
            {
                while(nn>=0)
                {
                    v.erase(number[nn]+v.begin());
                    nn--;
                }
            }
        }
    }

    if(v.size()==0)
        printf("yes\n");
    else
        printf("no\n");
}

v.clear();
ma.clear();
    }
    return 0;
}
