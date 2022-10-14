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
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0,0};
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        pair<int,int> cur = {0,0};
        cur.first = max(left.first,right.first) + 1;
        cur.second = max({left.first+right.first+1,left.second,right.second});
        return cur;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).second-1;
    }
};