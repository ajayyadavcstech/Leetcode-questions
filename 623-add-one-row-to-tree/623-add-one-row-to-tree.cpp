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
    void solve(TreeNode* root,int val,int depth){
        if(!root) return ;
        if(depth==1){
            TreeNode* node_left = new TreeNode(val);
            TreeNode* node_right = new TreeNode(val);
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            
            root->left = node_left;
            node_left->left = left;
            root->right = node_right;
            node_right->right = right;
            return ;
        }
        solve(root->left,val,depth-1);
        solve(root->right,val,depth-1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        } 
        solve(root,val,depth-1);
        return root;
    }
};