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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
          int ans=INT_MIN;
        while(q.empty()==false)
        {
            int size=q.size();
            int mini=q.front().second;
            int first,last;
          
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front().first;
                long long curr_level=q.front().second-mini;
                q.pop();
                if(i==0)first=curr_level;
                if(i==size-1)last=curr_level;
                if(node->left!=NULL)
                {
                    q.push({node->left,curr_level*2+1});
                }
                if(node->right!=NULL)
                {
                    q.push({node->right,curr_level*2+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};