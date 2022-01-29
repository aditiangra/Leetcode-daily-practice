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
    int maxLevelSum(TreeNode* root) {
        int level=0;
       if(root==nullptr)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int maxSum=INT_MIN;
        int maxLevel=0;
        while(q.empty()==false)
        {
            int size=q.size();
            level++;
            int sum=0;
            while(size>0)
            {
                TreeNode* node=q.front();
                q.pop();
                sum+=node->val;
                size--;
                if(node->left!=nullptr)q.push(node->left);
                if(node->right!=nullptr)q.push(node->right);
            }
            if(maxSum<sum){
                maxSum=sum;
                maxLevel=level;
            }
        }
        return maxLevel;
    }
};