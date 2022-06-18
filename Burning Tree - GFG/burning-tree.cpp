// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  Node* mark_parents(map<Node*,Node*>& nodeToParent,Node* root,int target)
  {
      Node* given=NULL;
      queue<Node*>q;
      q.push(root);
      nodeToParent[root]=NULL;
      while(q.empty()==false)
      {
          Node* node=q.front();
          q.pop();
          if(node->data==target)
          {
              given=node;
          }
          if(node->left!=NULL)
          {
              nodeToParent[node->left]=node;
              q.push(node->left);
          }
          if(node->right!=NULL)
          {
              nodeToParent[node->right]=node;
              q.push(node->right);
          }
      }
      return given;
  }
  int burnTree(map<Node*,Node*>& nodeToParent,Node* root,Node* given)
  {
      map<Node*,bool>visited;
      queue<Node*>q;
      q.push(given);
      visited[given]=true;
      int ans=0;
      while(q.empty()==false)
      {
          int size=q.size();
          bool flag=0;
          for(int i=0;i<size;i++)
          {
              Node* node=q.front();
              q.pop();
              if(node->left!=NULL && visited[node->left]==false)
              {
                  flag=1;
                  visited[node->left]=true;
                  q.push(node->left);
              }
               if(node->right!=NULL && visited[node->right]==false)
              {
                  flag=1;
                  visited[node->right]=true;
                  q.push(node->right);
              }
               if(nodeToParent[node]!=NULL && visited[nodeToParent[node]]==false)
              {
                  flag=1;
                  visited[nodeToParent[node]]=true;
                  q.push(nodeToParent[node]);
              }
          }
          if(flag==1)ans++;
        
      }
      return ans;
  }
    int minTime(Node* root, int target) 
    {
        // Your code goes her
        map<Node*,Node*>nodeToParent;
        Node* given=mark_parents(nodeToParent,root,target);
        return burnTree(nodeToParent,root,given);
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends