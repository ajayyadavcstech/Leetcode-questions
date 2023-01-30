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
    int total_camera;
    int solve(TreeNode* root){
        if(!root) return 1;
        int l = solve(root->left);
        int r = solve(root->right);
        
        if(l==-1 || r==-1){
            total_camera++;
            return 0;
        }
        if(l==0 || r==0) return 1;
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        return solve(root)==-1 ? total_camera+1 : total_camera;
    }
};