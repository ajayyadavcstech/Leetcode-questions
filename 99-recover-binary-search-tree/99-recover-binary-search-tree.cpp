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
    vector<TreeNode*> v;
    void inorder(TreeNode* root){
        if(root==NULL) return ;
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int s;
        int e;
        for( s=0;s<v.size()-1;s++){
            if(v[s]->val>v[s+1]->val) break;
        }
        for(e=v.size()-1;e>0;e--){
            if(v[e]->val<v[e-1]->val) break;
        }
        swap(v[s]->val,v[e]->val);
    }
};