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
    bool has_path(TreeNode* root,int target){
        if(root==NULL) return false;
        target-=root->val;
        if(!root->left && !root->right && !target) return true;
        return has_path(root->left,target) || has_path(root->right,target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return has_path(root,targetSum);
    }
};