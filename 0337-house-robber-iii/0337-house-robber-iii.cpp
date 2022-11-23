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
        pair<int,int> p1,p2,p3;
        p1 = solve(root->left);
        p2 = solve(root->right);
        p3.first = root->val + p1.second + p2.second;
        p3.second = max(p1.first+p2.first,max(p1.second+p2.second,max(p1.first+p2.second,p1.second+p2.first)));
        return p3;
    }
    int rob(TreeNode* root) {
          pair<int,int> p = solve(root);
        return max(p.first,p.second);
    }
};