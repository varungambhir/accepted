#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <string>
#include <deque>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <limits>
#include <numeric>
#include <complex>
#include <cassert>
#include <cmath>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>

using namespace std;

template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
template<typename X> inline void print(const X& a,int N) {cout<<endl;for(int i=0;i<N;i++)cout<<a[i]<<" ";cout<<endl;}
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pp;
typedef pair<ld, ld> ppld;
typedef unsigned long long ull;

#define swap(a,b) a^=b^=a^=b;
#define FOR(i, n) for(int i = 0; i < int(n); i++)
#define FORD(i, n) for(int i = int(n-1); i >= 0; i--)
#define FORAB(i, a, b) for(int i = int(a); i < int(b); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
#define mp make_pair
#define mset(a, val) memset(a, val, sizeof (a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define getcx getchar_unlocked
#define getmid(a,b) (a+(b-a)/2)
#define FORTR(it, container) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

const int INF = int(1e9);
const ll INF64 = ll(INF) * ll(INF);
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);

template<typename X> inline void inp(X &n ) {
int ch=getcx();int sign=1;n=0;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while(  ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
}
template<typename X> inline void out(X a) {
char snum[20]; int i=0;
do {snum[i++]=a%10+48; a=a/10; }while(a!=0);
i=i-1;
while(i>=0) putchar_unlocked(snum[i--]);
putchar_unlocked('\n');
}
#define MOD 1000000007

int dp[101][101] = {0};
int arr[101];

int main(){
    int N; inp(N);
    FOR(i,N){
        inp(arr[i+1]);
    }
    FOR(len,N)
    {
        for(int i=1;i<=N;i++)
        {
            int j = len+i;
            if(j>N) 
                continue;
            if(i == j)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i][j-1];
            for(int k=i;k<j;k++)
            {
                if(arr[j]>0 and arr[k]==-arr[j])
                {
                    if(k==i)
                    {
                        dp[i][j] = (dp[i][j] + 1+dp[k+1][j-1])%MOD; 
                    }
                    else
                    {
                        dp[i][j] = (dp[i][j] + ((1+dp[k+1][j-1])*(1+dp[i][k-1]))%MOD )%MOD; 
                    }
                }
            }
        }
    }
    out(dp[1][N]+1);
    return 0;
}