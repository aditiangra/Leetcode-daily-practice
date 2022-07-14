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
     void help(TreeNode* root,vector<int>&cnt)
{
    if(root==nullptr)return ;
    help(root->left,cnt);
    cnt.push_back(root->val);
    help(root->right,cnt);

}
    int countNodes(TreeNode* root) {
         vector<int> cnt;
    help(root,cnt);
    return cnt.size();
    }
    
};