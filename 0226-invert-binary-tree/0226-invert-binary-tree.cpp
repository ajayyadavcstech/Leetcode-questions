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
    void Invert(TreeNode* node){
        if(!node) return ;
        TreeNode* l = node->left;
        TreeNode* r = node->right;
        Invert(node->left);
        Invert(node->right);
        node->left = r;
        node->right = l;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        Invert(root);
        return root;
    }
};