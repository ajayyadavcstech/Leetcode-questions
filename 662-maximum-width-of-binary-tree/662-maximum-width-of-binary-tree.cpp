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
    unordered_map<int,pair<long long,long long>> mp;
    void solve(TreeNode* root,unsigned long long ind,int level,int &mx){
        if(root==NULL) return ;
        if(mp.find(level)==mp.end()) {
            mp[level].first = ind;
            mp[level].second = ind;
        }
        mp[level].first = (mp[level].first<ind) ? mp[level].first : ind;
        mp[level].second = (mp[level].second>ind) ? mp[level].second : ind;
        mx = max(mx,int(mp[level].second-mp[level].first+1));
        solve(root->left,2*ind+1,level+1,mx);
        solve(root->right,2*ind+2,level+1,mx);
    }
    int widthOfBinaryTree(TreeNode* root) {
        int mx = 0;
        solve(root,0,0,mx);
        return mx;
    }
};