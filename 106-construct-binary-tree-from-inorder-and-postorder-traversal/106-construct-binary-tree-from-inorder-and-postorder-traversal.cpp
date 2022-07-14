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
    TreeNode* solve(vector<int>&inorder,vector<int>&postorder,int s,int e){
        if(s>e) return NULL;
        
        TreeNode* node = new TreeNode(postorder[ind]);
        int mid = find(inorder,s,e,postorder[ind--]);
        
        node->right = solve(inorder,postorder,mid+1,e);
        node->left = solve(inorder,postorder,s,mid-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        ind = postorder.size()-1;
        return solve(inorder,postorder,0,postorder.size()-1);
    }
};