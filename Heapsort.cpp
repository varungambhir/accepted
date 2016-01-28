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

int heapsize = -1;

void maxheapify(int *, int);
void heapsort(int *, int);
void printarr(int* ,int);

int main(int argc, char const *argv[])
{
  int arr[] = {-1,12,11,13,5,6,7};
  int size = sizeof(arr)/sizeof(arr[0]);

  cout << "Given array is \n";
  printarr(arr,size-1);
  cout << "\n";
  heapsort(arr,size-1);

  cout << "Sorted array is \n"; 
  printarr(arr,size-1);

  return 0;
}

void maxheapify(int arr[],int node)
{
  int l = node<<1;
  int r = l+1;
  int largest = node;

  if( l<= heapsize && arr[largest] < arr[l])
    largest = l;
  
  if(r<= heapsize && arr[largest] < arr[r])
    largest = r;

  if(largest != node)
  {
    swap(arr[node],arr[largest]);
    maxheapify(arr,largest);
  }
  return;
}

void heapsort( int arr[], int n )
{
  heapsize = n;
  for(int i = n/2; i >= 1; i--)
  {
    maxheapify(arr,i);
  }

  printarr(arr,n);
 
  while(heapsize > 1)
  {
    swap(arr[1],arr[heapsize]);
    heapsize--;
    maxheapify(arr,1);
    //printarr(arr,n);
  }

}

void printarr(int *a,int n)
{
  FOR(i,1,n+1)
  {
    cout << a[i] << " ";
  }
  cout << "\n";
}