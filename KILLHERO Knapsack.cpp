#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define SL(x) scanf("%lld",&x)
#define F first
#define S second
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define MAX 510
#define MOD 1000000007
#define endl "\n"
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef pair<int,int> pii;

int D[MAX] , A[MAX];
int K[60][MAX][MAX];

int main() 
{
    int t;
    SD(t);
    while(t--)
    {
        int n,H,J;
        SD(n);
        SD(H);
        SD(J);
        FOR(i,0,n)
        {
            SD(D[i]);
        }
        FOR(i,0,n)
        {
            SD(A[i]);
        }
        FOR(i,0,n+1)
        {
            FOR(j,0,H+1)
            {
                FOR(k,0,J+1)
                {
                    if(!i || !j || !k)
                        K[i][j][k] = 0;

                    else if ( (j <= D[i-1]) || (k <= A[i-1]) )
                        K[i][j][k] = K[i-1][j][k];
                    else
                    {
                        K[i][j][k] = std::max(1 + K[i-1][j-D[i-1]][k-A[i-1]] , K[i-1][j][k]);
                    }
                }
            }
        }
        
        printf("%d\n", K[n][H][J]);

    }
    
    return 0;
}