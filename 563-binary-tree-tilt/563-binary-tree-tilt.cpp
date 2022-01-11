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
    int findTilt(TreeNode* root) {
         int tilt=0;
        if(root==NULL)return tilt;
        solve(root,tilt);
        return tilt;
    }
    int solve(TreeNode* root,int &tilt)
    {
        if(root==nullptr)return 0;
        int l=solve(root->left,tilt);
        int r=solve(root->right,tilt);
        tilt+=abs(l-r);
        return l+r+root->val;
    }
};