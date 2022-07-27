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
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int total=0;
        f(root,sum,total);
        return total;
    }
    void f(TreeNode* root,int sum,int &total)
    {
        if(root==nullptr)
        {
           return;
        }
          sum=sum*10+root->val;
        if(root->left==nullptr and root->right==nullptr)
        {
            total+=sum;
            sum=0;
            return ;
        }
      
      if(root->left)f(root->left,sum,total);
      if(root->right)f(root->right,sum,total);
        
    }
};