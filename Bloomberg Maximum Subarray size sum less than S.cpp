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
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
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

/* type your code here 

array of length n, 

the maximum size subarray such that the sum of elements in that subarray <= B,

return the size

*/

//0,1, 2, 3, 4, 5, 6, 7


int findLength(vector<int> nums, int B) {
    // code here
  int max_len = 0;
  int i , j;
  i = j = 0;
  int len = nums.size();
  if(!len) {
    return 0;
  }
  int cur_sum = nums[0];
  int cur_len = 1;

  while( j < len) {
    while( cur_sum <= B && j<len) {
      max_len = max(max_len,cur_len);
      j++;
      cur_sum += nums[j];
      cur_len++;
    }
        //inc i
    while(cur_sum > B && i<=j && j < len) {
      cur_sum -= nums[i];
      i++;
      cur_len--;
    }
    if(i > j) {
      j = i;
      if(j > len) break;
      cur_sum = nums[i];
      cur_len = 1;
    }
  }
  return max_len;
}

int main(int argc, char const *argv[])
{
  BOOST;
  std::vector<int> v{100,2,3,40,5,6,7,8,9};
  cout << findLength(v,10);
  cout << endl;
  return 0;
}