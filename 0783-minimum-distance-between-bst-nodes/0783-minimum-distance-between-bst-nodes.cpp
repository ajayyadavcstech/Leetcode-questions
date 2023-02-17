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
    void Inorder(TreeNode* root,int &pre,int &ans){
        if(!root) return ;
        Inorder(root->left,pre,ans);
        if(pre==INT32_MIN) pre = root->val;
        else ans = min(ans,root->val-pre);
        pre = root->val;
        Inorder(root->right,pre,ans);
    }
    int minDiffInBST(TreeNode* root) {
        int ans = INT32_MAX;
        int pre = INT32_MIN;
        Inorder(root,pre,ans);
        return ans;
    }
};