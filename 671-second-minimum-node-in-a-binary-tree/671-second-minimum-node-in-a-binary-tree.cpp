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
    int findSecondMinimumValue(TreeNode* root) {
        if(root==nullptr)return -1;
        set<int>s1;
        inorder(s1,root);
        if(s1.size()==1)return -1;
        else
            s1.erase(s1.begin());
        return *(s1.begin());
    }
    void inorder(set<int>&s1,TreeNode* root)
    {
        if(root==nullptr)return ;
        inorder(s1,root->left);
        s1.insert(root->val);
        inorder(s1,root->right);
    }
};