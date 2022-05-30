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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>inorder1,inorder2;
        helper(root1,inorder1);
        helper(root2,inorder2);
        int n=inorder1.size();
        int m=inorder2.size();
        vector<int> ans(n+m);
        merge(inorder1.begin(),inorder1.end(),inorder2.begin(),inorder2.end(),ans.begin());
        sort(ans.begin(),ans.end());
        return ans;
        
    }
    void helper(TreeNode* root,vector<int>& ans)
    {
        if(root==NULL)return;
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }
};