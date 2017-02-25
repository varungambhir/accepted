/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define LEFT 10
#define RIGHT 20
#define PRE 30
#define POST 40
#define tn TreeNode
#define pii pair<TreeNode* , int>
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack< pii > s;
        vector<int> res;
        tn* cur;
        int state;
        if(root != NULL) {
            cur = root;
            s.push(pii(root, PRE));
            
            while(!s.empty()) {
                pii temp = s.top();
                s.pop();
                cur = temp.first;
                state = temp.second;
                //if(cur == NULL) continue;
                
                if(state == PRE) {
                    s.push(pii(cur, POST));
                    
                    if(NULL != cur->right)
                    s.push(pii(cur->right, PRE));
                    
                    if(NULL != cur->left)
                    s.push(pii(cur->left, PRE));
                    
                } else if(state == POST) {
                    res.push_back(cur->val);
                    cur = NULL;
                }
            }
        }
        return res;
    }
};



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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(NULL == root) return res;
        stack<tn*> s;
        tn *cur = root;
        
        while(!s.empty() || cur != NULL) {
            
            if(cur != NULL) {
                if(NULL == cur->left && NULL == cur->right) {
                    res.push_back(cur->val);
                    cur = NULL;
                } else {
                    s.push(cur);
                    cur = cur->left;
                }
            }    
            // cur null pop stack
            else if(!s.empty()) {
                cur = s.top();
                res.push_back(cur->val);
                cur = cur->right;
                s.pop();
            }
        }
        return res;
    }
};


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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<tn*> s;
        vector<int> res;
        if(NULL == root) return res;
        s.push(root);
        
        while(!s.empty()) {
            tn *cur = s.top();
            s.pop();
            res.push_back(cur->val);
            if(NULL != cur->right)
                s.push(cur->right);
            if(NULL != cur->left)
                s.push(cur->left);
        }
        return res;
    }
};