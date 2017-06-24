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


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define tn TreeNode
class Solution {
public:

  int findss(vector<int> &arr, int st, int en, int val) {
    for(int i = st; i <= en ; i++) {
      if(arr[i] == val)
        return i;
    }
    return -1;
  }

  int j = 0;
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    if(!n) return NULL;
    j = 0;
    return buildUtil(preorder, inorder, 0,n-1);
  }

  TreeNode* buildUtil( vector<int> &preorder, vector<int> &inorder, int st, int en) {
    
    if(st > en) 
      return NULL;
    tn *cur = new TreeNode(preorder[j++]);
    // /trace(st,en,j, cur->val);
    if(st == en) return cur;
    
    int ind = findss(inorder, st, en, cur->val);
    cur->left = buildUtil(preorder, inorder, st, ind-1);
    cur->right = buildUtil(preorder, inorder, ind+1, en);

    return cur;
  }
};
int main(int argc, char const *argv[])
{
  BOOST;
  std::vector<int> inorder{1,2,3};
  std::vector<int> preorder{3,2,1};
  Solution d;
  TreeNode *res = d.buildTree(preorder, inorder);
  return 0;
} 