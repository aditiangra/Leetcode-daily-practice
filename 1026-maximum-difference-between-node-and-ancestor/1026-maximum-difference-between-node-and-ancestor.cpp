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
    int maxAncestorDiff(TreeNode* root,int minV = INT_MAX, int maxV = INT_MIN) {
       return root ? max(maxAncestorDiff(root->left, minV = min(minV, root->val), maxV = max(maxV, root->val)), maxAncestorDiff(root->right, minV, maxV)) : maxV - minV;
      
    }
};