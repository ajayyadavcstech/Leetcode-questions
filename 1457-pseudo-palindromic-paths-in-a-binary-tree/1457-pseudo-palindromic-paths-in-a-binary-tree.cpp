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
    unordered_map<int,int> mp;
    int Possiblepalindrome(){
        int odd = 0;
        for(auto x : mp){
            if(x.second&1) odd++;
            if(odd>1) return 0;
        }
        return 1;
    }
    
    int solve(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right){
            mp[root->val]++;
            int cnt = Possiblepalindrome();
            mp[root->val]--;
            return cnt;
        }
        
        mp[root->val]++;
        int cnt = solve(root->left) + solve(root->right);
        mp[root->val]--;
        return cnt;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return solve(root);
    }
};