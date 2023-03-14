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
    int sumNumbers(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,root->val});
        int ans = 0;
        while(q.size()){
            TreeNode* node = q.front().first;
            int cur_sum = q.front().second;
            q.pop();
            if(!node->left && !node->right){
                ans+=cur_sum;
            }
            else{
                if(node->left) q.push({node->left,cur_sum*10+node->left->val});
                if(node->right) q.push({node->right,cur_sum*10+node->right->val});
            }
        }
        return ans;
    }
};