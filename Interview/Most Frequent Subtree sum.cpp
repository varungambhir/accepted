/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define tn TreeNode
class Solution {
public:
    
    template <typename T1, typename T2>
    struct greatestSecond {
        typedef pair<T1, T2> type;
        bool operator()(type const &a, type const &b) const {
            return a.second > b.second;
        }
    };

    map<int, int> m;
    
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        m.clear();
        
        vector<int> res;
        
        set<int> s;
        
        if(root == NULL) {
            return res;
        }
        
        sumSubTree(root);
        
        vector< pair<int,int> > mcopy(m.begin(), m.end());
        
        sort(mcopy.begin(),mcopy.end(), greatestSecond<int,int>() );
        
        int x = 0;
        int maxi;
        
        for(auto &it : mcopy) {
            x++;
            if(x == 1) {
                maxi = it.second;
                s.insert(it.first);
            } else {
                if( it.second != maxi) break;
                s.insert(it.first);
            }
        }
        
        for(auto &i : s) {
            res.push_back(i);
        }
        return res;
    }
    
    int sumSubTree(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }
        int sum = sumSubTree(root->left) + sumSubTree(root->right) + root->val;
        m[sum] += 1 ;
        return sum;
    }
};