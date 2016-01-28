#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define F first
#define S second
#define L 2*node
#define R 2*node+1
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define MAX 200010
#define MOD 1000000007


int arr[1001000];
int main(int argc, char const *argv[])
{
    BOOST;
    int n,k;
    cin>>n;
    FOR(i,0,n)
    {
        cin>>arr[i];
    }
    cin>>k;
    std::deque<int> Q(k);

    FOR(i,0,k)
    {
        while(!Q.empty() && arr[i]>=arr[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }
    FOR(i,k,n)
    {
        cout<<arr[Q.front()]<<" ";
        //out of range
        while(!Q.empty() && (Q.front()+k<=i) )
            Q.pop_front();
        // remove all from i-1 to 0 as they will no longer be needed
        // if A[i] >= A[k] where k = [0,i-1]
        while( !Q.empty() && arr[i] >= arr[Q.back()])
            Q.pop_back();

        Q.push_back(i);
    }
    cout<<arr[Q.front()]<<" ";
    cout<<endl;

return 0;
}