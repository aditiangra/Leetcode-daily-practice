
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
          int sum=0;
        helper(root,sum);
       return root; 
    }
       void helper(TreeNode* root,int &sum)
    {
        if(root==NULL)return;
        helper(root->right,sum);
        root->val+=sum;
          sum=root->val;
        helper(root->left,sum);
    }
};