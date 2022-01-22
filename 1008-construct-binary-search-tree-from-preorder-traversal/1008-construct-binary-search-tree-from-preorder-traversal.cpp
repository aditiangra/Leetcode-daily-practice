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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       if(preorder.size()==0)return nullptr;
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++)
        {
            insertIntoBst(root,preorder[i]);
        }
        return root;
    }
    void insertIntoBst(TreeNode* root,int val)
    {
        if(root==NULL)return ;
        TreeNode* curr=root;
        while(true)
        {
            if(curr->val<=val)
            {
                if(curr->right!=nullptr)curr=curr->right;
                 else
            {
                curr->right=new TreeNode(val);
                return;
            }
            }
            else
            {
                if(curr->left!=nullptr)curr=curr->left;
                else
                {
                    curr->left=new TreeNode(val);
                    return;
                }
            }
           
        }
    }
};