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
    bool solve(TreeNode* root,long  left=INT64_MIN,long right=INT64_MAX){
        if(root==NULL) return true;
        else return (root->val>left && root->val<right && solve(root->left,left,root->val) && solve(root->right,root->val,right));
    }
    bool isValidBST(TreeNode* root) {
        return solve(root);
    }
};