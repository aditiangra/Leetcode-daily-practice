/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>v;
    vector<int> postorder(Node* root) {
        if(root==nullptr)return v;
        for(int i=0;i<root->children.size();i++)
        {
            postorder(root->children[i]);
        }
        v.push_back(root->val);
        return v;
        
    }
};