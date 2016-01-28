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

#define inf 1000000000
#define MAXN 2000

using namespace std;


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

int main()
{
    int n;
    scanint(n);
    int a[MAXN];
    while (n) {
        for (int i = 0; i < n; ++i) {
            scanint(a[i])
        }
        sort(a, a + n);
        
        int sol = 0;
        for (int i = n-1; i > 1; --i) {
            int j = 0, k = i-1;
            while(j<k) {
                while(j<k && a[j]+a[k] >= a[i]) 
                    k--;
                sol += k-j;
                ++j;
            }
        }
        
        printf("%d\n", sol);
        
        scanint(n);
    }
    
    return 0;
}
