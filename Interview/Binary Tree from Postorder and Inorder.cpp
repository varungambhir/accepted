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

    int find(vector<int> &arr , int val, int st, int en) {
        for(int i = st; i <=  en ; i++)
            if(arr[i] == val)
            return i;
        return -1;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        if(!n) return NULL;
        int root_val = postorder[n-1];
        int inord = find(inorder, root_val, 0 , n-1);
        tn *root = new TreeNode(postorder[n-1]);
        int j = n-2;
        root->right = buildUtil(inorder, postorder, inord+1, n-1, &j);
        // j modified
        root->left = buildUtil(inorder, postorder, 0, inord-1, &j);
        return root;
    }
    
    tn *buildUtil(vector<int> &inorder, vector<int>& postorder, int startInd,int endInd, int *postInd) {
        
        if(startInd > endInd)
        return NULL;
        
        TreeNode *cur = new TreeNode(postorder[*postInd]);
        (*postInd) -= 1;
        
        if(startInd == endInd)
            return cur;
            
        int inord = find(inorder, cur->val, startInd, endInd);    
        cur->right = buildUtil(inorder, postorder, inord+1, endInd, postInd);
        cur->left = buildUtil(inorder, postorder, startInd, inord-1, postInd);
        return cur;
    }
};

int main(int argc, char const *argv[])
  {
    BOOST;
    std::vector<int> inorder{1,2,3,4,5,6};
    std::vector<int> postorder{2,3,6,5,4,1};
    Solution d;
    TreeNode *res = d.buildTree(inorder, postorder);
    return 0;
  } 