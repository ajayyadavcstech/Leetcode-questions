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
    int ans;
    void solve(TreeNode* root,int num){
        if(!root) return ;
        if(!root->left && !root->right){
            ans+=(num*10+root->val);
            return ;
        }
        
        solve(root->left,num*10+root->val);
        solve(root->right,num*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};