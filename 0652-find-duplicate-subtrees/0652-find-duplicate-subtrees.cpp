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
    string preorder(TreeNode* root,vector<TreeNode*> &ans,unordered_map<string,int> &mp){
        if(!root) return "@";
        string str = to_string(root->val) + "#" + preorder(root->left,ans,mp) + "#" + preorder(root->right,ans,mp);
        mp[str]++;
        if(mp[str]==2) ans.push_back(root);
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string,int> mp;
        preorder(root,ans,mp);
        return ans;
    }
};