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


//https://leetcode.com/problems/4sum/

class Solution {
public:
    
    pair<int,int> makes_pair(int a,int b) {
        return make_pair(min(a,b), max(a,b));
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        set< pair<int,int> > twosums;
        int len = nums.size();
        map<int, set< pair<int,int> > > m;
        
        for(int i = 0; i < len-1 ; i++) {
            for(int j = i+1; j < len ; j++) {
                //if( twosums.find( makes_pair(i,j) ) == twosums.end() ) {
                    twosums.insert(makes_pair(i,j));
                    m[nums[i] + nums[j]].insert(makes_pair(i,j));            
                
            }
        }
        // a+ b done
        // now to find target -(c+d)
        vector<int> temp;
        for(pair<int,int> i : twosums) {
            int a = i.first;
            int b = i.second;
            int sumd = nums[a]+ nums[b];
            int val = target - sumd;
            
            if( m.find(val) != m.end() ) {
                for(pair<int,int> j : m[val]) {
                    int c = j.first;
                    int d = j.second;
                    if(a == c || a ==d || b  == c || b == d)
                    continue;
                    vector<int> temp{nums[a], nums[b], nums[c], nums[d]};
                    sort(temp.begin(),temp.end());
                    if(find(res.begin(), res.end(), temp) == res.end())
                    res.push_back(temp);
                }
            }
            
        }
        return res;
    }
};


//https://leetcode.com/problems/4sum/
int main(int argc, char const *argv[])
{
  BOOST;
  return 0;
} 