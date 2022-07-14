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
    int ind;
    int find(vector<int>&inorder,int s,int e,int val){
        for(int i=s;i<=e;i++){
            if(inorder[i]==val) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int> &preorder,vector<int> &inorder,int s,int e){
        if(s>e) return NULL;
        
        TreeNode* node = new TreeNode(preorder[ind]);
        int mid = find(inorder,s,e,preorder[ind++]);
        
        node->left = solve(preorder,inorder,s,mid-1);
        node->right = solve(preorder,inorder,mid+1,e);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,inorder,0,inorder.size()-1);
    }
};