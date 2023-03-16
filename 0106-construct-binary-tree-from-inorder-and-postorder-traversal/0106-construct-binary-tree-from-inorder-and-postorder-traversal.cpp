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
    TreeNode* build(vector<int>&inorder,vector<int>&postorder,int s,int e,unordered_map<int,int>&mp,int &i){
        if(s>e) return NULL;
        if(i==-1) return NULL;
        
        int ind = mp[postorder[i]];
        TreeNode* node = new TreeNode(postorder[i]);
        i--;
        
        node->right = build(inorder,postorder,ind+1,e,mp,i);
        node->left = build(inorder,postorder,s,ind-1,mp,i);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]] = i;
        int ind = inorder.size()-1;
        return build(inorder,postorder,0,inorder.size()-1,mp,ind);
    }
};