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
    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        inorder(arr,root);
        int i=0,j=arr.size()-1;
        while(i<j)
        {
            int sum=arr[i]+arr[j];
            if(sum==k)return true;
            else if(sum>k)j--;
            else if(sum<k)i++;
        }
        return false;
    }
    void inorder(vector<int>&arr,TreeNode* root)
    {
        if(root==nullptr)return;
        inorder(arr,root->left);
        arr.push_back(root->val);
        inorder(arr,root->right);
    }
};