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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s){
             return false;
         }   
         else if(isSameTree(s,t)){
             return true;
         }
         else{
             return isSubtree(s->left,t) || isSubtree(s->right,t);
         }
    }
     bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr and q==nullptr)return true;
        if(p==nullptr or q==nullptr)return false;
        if(p->val!=q->val)return false;
        return isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
    }
};