#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define F first
#define S second
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define MAX 500010
#define MOD 1000000007
#define endl "\n"
//#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef pair<int,int> pii;

int w[105][105]; 

int main() 
{
    int t;
    SD(t);
    int m,n;
    while(t--)
    {
        SD(m);SD(n);
        FOR(i,0,m)
        FOR(j,0,n)
        SD(w[i][j]);
        int ans = INT_MIN;
        int val,k ,ii,jj;
        FOR(i,0,m)
        {
            FOR(j,0,n)
            {   
                val = w[i][j];
                for( k = 1; k<102;k++)
                {
                    if( (i+k)>=m || (j+k)>=n || (i-k)<0 || (j-k)<0 )
                        break;  
                    val += ( w[i-k][j-k] + w[i-k][j+k]  + w[i+k][j-k] + w[i+k][j+k] );
                    ans = std::max(ans,val);
                }

                for(k=1 ; k <102; k+=2)
                {
                    val = 0;
                    if( (i+k)>=m || (j+k)>=n)
                        break;
                    ii = i;
                    jj = j;
                    while(ii!=(i+k))
                    {
                        val += (w[ii++][jj++]);
                    }
                    val += w[ii][jj];

                    ii = i+k;
                    jj = j;
                    while(ii != i)
                    {
                        val +=( w[ii--][jj++] ) ;
                    }
                    val += (w[ii][jj]);

                    ans = std::max(ans,val);

                }


            }
        }

        printf("%d\n",ans);
    }
    return 0;
}