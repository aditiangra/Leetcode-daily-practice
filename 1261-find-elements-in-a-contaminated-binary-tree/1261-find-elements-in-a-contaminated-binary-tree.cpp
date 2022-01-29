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
class FindElements {
public:
    unordered_map<int,int>mpp;
    FindElements(TreeNode* root) {
        if(root!=nullptr)
        {
            root->val=0;
            queue<TreeNode*>q;
            q.push(root);
            mpp[0]++;
            while(q.empty()==false)
            {
                TreeNode* temp=q.front();
                q.pop();
                int x=temp->val;
                if(temp->left!=nullptr)
                {
                    temp->left->val=2*x+1;
                    mpp[2*x+1]++;
                    q.push(temp->left);
                }
                if(temp->right!=nullptr)
                {
                    temp->right->val=2*x+2;
                    mpp[2*x+2]++;
                    q.push(temp->right);
                }
            }
        }
    }
    
    bool find(int target) {
       return (mpp.find(target) != mpp.end()); 
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */