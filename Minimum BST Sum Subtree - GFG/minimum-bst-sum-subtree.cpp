//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public: // {bool,sum,lenght}
    vector<int> ValidBST(Node* root,int l,int r){
        if(!root) return {1,0,0};
        if(!(root->data>=l && root->data<=r)) return {0,0,0};
        vector<int> left = ValidBST(root->left,l,root->data-1);
        vector<int> right = ValidBST(root->right,root->data+1,r);
        if(left[0]==0 || right[0]==0) return {0,0,0};
        return {1,left[1]+right[1]+root->data,left[2]+right[2]+1};
    }
    void solve(Node* root,int &ans,int &target){
        if(!root) return ;
        vector<int> cur = ValidBST(root,INT32_MIN,INT32_MAX);
        // cout<<root->data<<" "<<cur[0]<<" "<<cur[1]<<" "<<cur[2]<<endl;
        if(cur[0]==1 && cur[1]==target) ans = min(ans,cur[2]);
        solve(root->left,ans,target);
        solve(root->right,ans,target);
    }
    int minSubtreeSumBST(int target, Node *root) {
        // code here
        int ans = INT32_MAX;
        solve(root,ans,target);
        return ans==INT32_MAX ? -1 : ans;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends