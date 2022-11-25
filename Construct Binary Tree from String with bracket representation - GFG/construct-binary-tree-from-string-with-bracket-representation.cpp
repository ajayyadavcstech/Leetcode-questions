//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    Node* solve(string &s,int &i){
        if(s[i]==')' || i>=s.size()) {
            return NULL;
        }
        
        int x = 0;
        if(s[i]=='(') i++;
        while(i<s.size() && s[i]>='0' &&s[i]<='9'){
            x = x*10 + s[i]-'0';
            i++;
        }
        Node* root=new Node(x);
        root->left = solve(s,i);
        root->right = solve(s,i);
        if(s[i]==')') i++;
        return root;
    }
    // function to construct tree from string
    Node *treeFromString(string str){
        // code here
        int i = 0;
        return solve(str,i);
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends