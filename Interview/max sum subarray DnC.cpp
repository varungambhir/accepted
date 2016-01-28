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
//#define L 2*node
//#define R 2*node+1
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
#define MAXN 100010
#define MOD 1000000007
 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/
#define sn struct node

// Find the maximum possible sum in arr[] auch that arr[m] is part of it
int maxCrossingSum(int arr[],int l,int mid,int r)
{
  int leftsum , rightsum;
  leftsum = rightsum = INT_MIN;
  int i;
  i = mid;
  int sum = 0;
  for(i = mid;i>=l;i--)
  {
    sum = sum + arr[i];
    leftsum = max(sum,leftsum);
  }
  sum =0;
  for(i = mid+1; i <= r; i++)
  {
    sum = sum + arr[i];
    rightsum = max(sum,rightsum);
  }

  return leftsum + rightsum;


}

int maxSubArraySum(int arr[],int l,int r)
{
  if(l == r)
    return arr[l];

  int m = (l+r)/2;

  return max( maxSubArraySum(arr,l,m),
             max(maxSubArraySum(arr,m+1,r),maxCrossingSum(arr,l,m,r) ));
}
 
/*Driver program to test maxSubArraySum*/
int main()
{
   int arr[] = {2, -3, -4, 5, 7};
   int n = sizeof(arr)/sizeof(arr[0]);
   int max_sum = maxSubArraySum(arr, 0, n-1);
   printf("Maximum contiguous sum is %d\n", max_sum);
   return 0;
}