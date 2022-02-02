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
class BSTIterator {
public:
    int curr=0,pos=0,arr[100001];
    BSTIterator(TreeNode* root) {
     dfs(root);
    }
    void dfs(TreeNode* root)
    {
        if(root==nullptr)return;
        dfs(root->left);
        arr[pos++]=root->val;
        dfs(root->right);
    }
    
    int next() {
        return arr[curr++];
    }
    
    bool hasNext() {
        return curr<pos;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */