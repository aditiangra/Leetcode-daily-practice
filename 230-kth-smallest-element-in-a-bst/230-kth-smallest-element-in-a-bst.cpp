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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int>pq;
        helper(pq,root,k);
        return pq.top();
    }
    void helper(priority_queue<int> &pq,TreeNode* root,int k)
    {
        //left-root----right//
        if(root==nullptr)return ;
        helper(pq,root->left,k);
        pq.push(root->val);
        if(pq.size()>k)
        {
            pq.pop();
        }
        helper(pq,root->right,k);
    }
};