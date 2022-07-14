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
    TreeNode* pre = NULL;
    TreeNode* node1 = NULL;
    TreeNode* node2 = NULL;
    void solve(TreeNode* root){
        if(root==NULL) return ;
        
        solve(root->left);
        if(pre==NULL){
            pre =root;
        }
        else{
            if(root->val<pre->val){
                if(node1==NULL){
                    node1 = pre;
                    node2 = root;
                }else if(node1!=NULL){
                    node2 = root;
                }
            }
        }
        pre = root;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        swap(node1->val,node2->val);
    }
};