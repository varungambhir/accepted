#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L 2*node
#define R 2*node+1
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
#define MAXN 1010
#define MOD 1000000007
#define INT_LMAX 12345678

ll sum1[MAXN][MAXN] , sum2[MAXN][MAXN] ;
ll sum3[MAXN][MAXN];
ll sum4[MAXN][MAXN];
ll P1[MAXN][MAXN] , P2[MAXN][MAXN] ;
ll P3[MAXN][MAXN] , P4[MAXN][MAXN];
ll A[MAXN][MAXN];

int main(int argc, char const *argv[])
{
    //BOOST;
    freopen("input.in","r",stdin);
    int m,n,x,y;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        FOR(i,0,n) FOR(j,0,m) cin>>A[i][j];

        FOR(i,0,n)
        {
            FOR(j,0,m)
            {
                if(!j)
                    sum1[i][j] = A[i][j];
                else
                    sum1[i][j] = A[i][j] + sum1[i][j-1];
            }
            ROF(j,m-1,0)
            {
                if(j==m-1)
                    sum2[i][j] = A[i][j];
                else
                    sum2[i][j] = A[i][j] + sum2[i][j+1];
            }
        }
        FOR(j,0,m)
        {
            FOR(i,0,n)
            {
                if(!i)
                    sum3[i][j] = A[i][j];
                else
                    sum3[i][j] = A[i][j] + sum3[i-1][j];
            }
            ROF(i,n-1,0)
            {
                if(i==n-1)
                    sum4[i][j] = A[i][j];
                else
                    sum4[i][j] = A[i][j] + sum4[i+1][j];
            }
        }

        ll min;
        int pos;

        FOR(i,0,n)
        {
            pos = 0;
            min = INT_LMAX;
            FOR(j,0,m)//2
            {
                if(min > sum2[i][j])
                {
                    min = sum2[i][j];
                    pos = j;
                }

                P2[i][j] = pos;
                cout << "i  " << i << " j " << j << " " << P2[i][j] << endl;
            }
            pos = m-1;
            min = INT_LMAX;
            ROF(j,m-1,0)
            {
                if(min > sum1[i][j])
                {
                    min = sum1[i][j];
                    pos = j;
                }

                P1[i][j] = pos;
            }
        }

        FOR(j,0,m)
        {
            min = INT_LMAX;
            FOR(i,0,n)
            {
                if(min > sum4[i][j])
                {
                    min = sum4[i][j];
                    pos = i;
                }
                P4[i][j] = pos;
            }

            min = INT_LMAX;
            ROF(i,n-1,0)
            {
                if(min > sum3[i][j])
                {
                    min = sum3[i][j];
                    pos = i;
                }
                P3[i][j] = pos;
            }
        }

        ll k = 0;
        ll ans = INT_LMAX;
        FOR(i,0,n)
        {

            FOR(j,0,m)
            {
                k=0;

                if(j!=0)
                    k +=  sum1[i][P1[i][j]] - sum1[i][j-1];
                else
                    k += sum1[i][P1[i][j]];

                if(j!=m-1)
                    k += sum2[i][P2[i][j]] - sum2[i][j+1];
                else
                    k += sum2[i][P2[i][j]];

                if(i!=0)
                    k += sum3[P3[i][j]][j] - sum3[i-1][j];
                else
                    k += sum3[P3[i][j]][j];

                if(i!=n-1)
                    k += sum4[P4[i][j]][j] - sum4[i+1][j];
                else
                    k+= sum4[P4[i][j]][j];

                k = k -3*A[i][j];
                ans = std::min(k,ans);
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}
