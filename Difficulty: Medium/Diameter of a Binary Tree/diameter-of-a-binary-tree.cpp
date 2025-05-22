//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}

Node* buildTree(string str) {
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
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
    int count=0;
    vector<int> str;
    void Csm(Node *root){
        if(root==NULL){
            return;
        }
        else if(root->left != NULL){
            count++;
            Csm(root->left);
        }
        else if(root->right != NULL)
        {
            count++;
            Csm(root->right);
        }
    }
    
    void Cbig(Node *root){
        if(root==NULL){
            return;
        }
        else if(root->right != NULL){
            count++;
            Cbig(root->right);
        }
        else if(root->left != NULL){
            count++;
            Cbig(root->left);
        }
    }
    
    void postorder(Node *root){
        
        if(root == NULL){
            return;
        }
        str.push_back(root->data);
        postorder(root->left);
        postorder(root->right);
    }
    
    int func(Node *root,int &res)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int l=func(root->left,res);
        int r= func(root->right,res);
        
        res = max(res,(l+r));
        return max(l,r) + 1;
    }
    
    int diameter(Node *root) {
        // Your code here
        
        int res=INT_MIN;
        func(root,res);
        return res;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends