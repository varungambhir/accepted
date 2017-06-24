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

//https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > v;
        int n = nums.size();
        if(n < 3) return v;
        sort(nums.begin(), nums.end());
        vector<int> &a = nums;
        map<vector<int> , bool> m;
        for(int i = 0 ; i <= n-2-1 ; i++) {
            int j = i+1;
            int k = n-1;
            
            while(j < k) {
                if(0 == a[i] + a[j] + a[k] ) {
                    vector<int> t{a[i],a[j],a[k]};
                    sort(t.begin(),t.end());
                    if(!m[t]) {
                        m[t] = true;
                        v.push_back(t);
                    }
                    k--;
                    j++;
                    //uniqu that's why j++
                } else if( a[i] + a[j] + a[k] > 0) {
                    k--;
                } else { //a[i] + a[j] + a[k] < 0
                    j++;
                }
                
            }    
            
        }
        return v;
    }
};
//https://leetcode.com/problems/3sum/
int main(int argc, char const *argv[])
{
  //3SUM
  return 0;
}