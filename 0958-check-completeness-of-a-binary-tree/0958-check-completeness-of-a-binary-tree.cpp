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
    int count(TreeNode* root){
        if(!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }
    bool isCompleteTree(TreeNode* root) {
       int total_node = count(root); 
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1;
        while(true){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                cnt++;
            }
            else break;
            if(node->right){
                q.push(node->right);
                cnt++;
            }
            else break;
        }
        return total_node==cnt;
    }
};