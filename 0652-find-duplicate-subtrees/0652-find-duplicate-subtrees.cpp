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
    map<vector<int>,vector<TreeNode*>> mp;
    void preorder(TreeNode* root,vector<int> &temp){
        if(!root){
            temp.push_back(INT32_MIN);
            return ;
        }
        temp.push_back(root->val);
        preorder(root->left,temp);
        preorder(root->right,temp);
    }
    void traverse(TreeNode* root){
        if(!root) return ;
        vector<int> temp;
        preorder(root,temp);
        mp[temp].push_back(root);
        traverse(root->left);
        traverse(root->right);
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        vector<TreeNode*> ans;
        for(auto &x:mp){
            if(x.second.size()>1) ans.push_back(x.second[0]);
        }
        return ans;
    }
};