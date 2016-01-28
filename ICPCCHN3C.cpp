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

ll dp[110][110];
ll arr[110] , n;

long long minUnhappiness(int l, int r){
    long long& res = dp[l][r];
    if(res != -1){
        return res;
    }
    if(l > r){
        res = 0;
        return res;
    }
    res = 1e9;
    //I.pick the rightmost
    int val = arr[r];
    int greater = 0, smaller = 0;
    for(int i=0; i<l; i++){
        if(arr[i] < val) smaller++;
        else if(arr[i] > val) greater++;
    }
    for(int i=r+1; i<n; i++){
        if(arr[i] < val) smaller++;
        else if(arr[i] > val) greater++;
    }

    res = min(res, min(smaller, greater) + minUnhappiness(l, r-1));
    debug(smaller);
    debug(greater); 
    cout<<" L:" <<l+1 <<" R: " << r+1 <<" Res : "<< res<<endl;
    //I. pick the leftmost
    val = arr[l];
    greater = smaller = 0;
    for(int i=0; i<l; i++){
        if(arr[i] < val) smaller++;
        else if(arr[i] > val) greater++;
    }
    for(int i=r+1; i<n; i++){
        if(arr[i] < val) smaller++;
        else if(arr[i] > val) greater++;
    }
    res = min(res, min(smaller, greater) + minUnhappiness(l+1, r));
    cout<<" L:" <<l+1 <<" R: " << r+1 <<" Res"<< res<<endl;
    return res;
}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        FOR(i,0,n)
        {
            cin>>arr[i];
        }
        memset(dp,-1,sizeof(dp));
        cout << minUnhappiness(0,n-1)<<endl;
    }

    return 0;
}