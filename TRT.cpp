#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,a[2000];
    long long dp[2][2000];
    
    scanf("%d",&N);
    for(int i = 0;i<N;++i) scanf("%d",&a[i]);
    
    for(int i = 0;i<N;++i) dp[1][i] = N*a[i];
    
    for(int i = 2;i<=N;++i) for(int j = 0;j+i-1<N;++j)
        dp[i&1][j] = max((N+1-i)*a[j]+dp[(i&1)^1][j+1],(N+1-i)*a[j+i-1]+dp[(i&1)^1][j]);
    
    printf("%lld\n",dp[N&1][0]);
    
    return 0;
}

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int a[2000];
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
        
    vector < vector <long long> > dp(n+1,vector <long long> (n+1,0));
    for(int i=0;i<=n;i++)
        dp[i][0] = dp[0][i] = 0;

    for(int i=1;i<=n;i++)
        dp[i][i] = a[i-1]*n;

    for(int i=n-1;i>=1;i--)
    {
        for(int k = i,j = n;k>=1  && j>=1 ; j--,k--)
        {
            int y = n - (j-k+1) + 1;
            dp[k][j] = max( dp[k+1][j] + a[k-1]*y , dp[k][j-1] + a[j-1]*y );
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}