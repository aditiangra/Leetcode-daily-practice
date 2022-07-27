/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string result;
    void solve(TreeNode* root,string running)
    {
        if(root==nullptr)return ;
        if(root->left==nullptr and root->right==nullptr)
        {
            running+=(root->val+'a');
            reverse(running.begin(),running.end());
            if(running.size()>0 and running<result)
            {
                result=running;
            }
            return;
        }
        running+=(root->val+'a');
        solve(root->left,running);
        solve(root->right,running);
    }
    string smallestFromLeaf(TreeNode* root) {
        result=string(1,'z'+1);
        solve(root,"");
        return result;
    }
};