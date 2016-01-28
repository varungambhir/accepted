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
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define MAXN 100005
#define MOD 1000000007

typedef pair<int,int> pii;
int arr[2000000+10]={0};
int main(int argc, char const *argv[])
{
  BOOST;
  int n;
  cin>>n;

  FOR(i,0,n)
  {
    arr[i] = i+1;
  }
  int ptr = 0;

  FOR(i,2,n+1)
  {
    int j = ptr;
    while(j<n+ptr)
    {
      swap(arr[j],arr[ptr]);
      j+=i;
    }

    swap(arr[ptr],arr[n+ptr]);
    ptr++;
 /*   cout<<endl;
    FOR(i,0,2*n+1)
  {

    cout<<arr[i]<<" ";
  }
*/
  }

  int i = n-1;
  while(arr[i]!=0)
  {
    cout<<arr[i++]<<" ";
  }
  cout<<endl;

  

  return 0;
}