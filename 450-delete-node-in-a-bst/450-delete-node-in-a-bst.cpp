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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)return root;
        if(root->val==key)return helper(root);
        TreeNode* dummy=root;
        while(root!=nullptr)
        {
            if(root->val >key)
            {
                if(root->left!=nullptr and root->left->val==key)
                { root->left=helper(root->left);
                 break;}
                else root=root->left;
            }
            else
            {
                if(root->right!=nullptr and root->right->val==key)
                { root->right=helper(root->right);
                 break;}
                else root=root->right;
            }
        }
        return dummy;
    }
    TreeNode* helper(TreeNode* root)
    {
        if(root->left==nullptr)return root->right;
        if(root->right==nullptr)return root->left;
        TreeNode* rightChild=root->right;
        TreeNode* lastRight=findLastRight(root->left);
        lastRight->right=rightChild;
        return root->left;
    }
    TreeNode* findLastRight(TreeNode* root)
    {
        if(root->right==nullptr)return root;
       return findLastRight(root->right);
    }
};