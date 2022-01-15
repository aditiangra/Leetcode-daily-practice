/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode*res=nullptr;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        solve(cloned,target);
        return res;
    }
    void solve( TreeNode* cloned, TreeNode* target)
    {
        if(cloned==nullptr)return;
        if(cloned->val==target->val)
        {
            res=cloned;
            return ;
        }
        solve(cloned->left,target);
        solve(cloned->right,target);
    }
};