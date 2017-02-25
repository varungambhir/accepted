#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),c.end(),x) != (c).end())
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
  template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
  template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
  #define trace(...)
#endif

ll MOD = 1000000007LL;

inline int parent(int i){
  return i>>1;
}
inline int leftC(int i) {
  return 1+i<<1;
} 
inline int rightC(int i){ 
  return 2+ i<<1;
}

void insertionSort(int arr[], int n) {
  int j = 1;
  for(int j = 1; j <= n-1 ; j++) {
    int key = arr[j];
    int i = j - 1;
    while(i >= 0 && arr[i] > key) {
      arr[i+1] = arr[i];
      i--;
    }
    arr[i+1] = key;
  }
  return;
}

int main(int argc, char const *argv[])
{
  BOOST;
  int i = 9 ;
  i = i >> 1;
  cout << i << endl;
  int arr[] = {10,3,6,9,2,4,6,1,9};
  int n = (sizeof(arr))/sizeof(arr[0]);
  insertionSort(arr, n);
  FOR(i,0,n-1) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
} 