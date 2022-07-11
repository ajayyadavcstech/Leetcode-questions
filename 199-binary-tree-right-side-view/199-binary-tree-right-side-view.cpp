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
    vector<int> rightView;
    void solve(TreeNode* root,int row=0){
        if(root==NULL) return ;
        
        if(rightView.size()==row){
            rightView.push_back(root->val);
        }
        solve(root->right,row+1);
        solve(root->left,row+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        solve(root);
        return rightView;
    }
};