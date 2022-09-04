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
class com{
    public:
        bool operator()(pair<int,int>& p1,pair<int,int>& p2){
        if(p1.second==p2.second) return p1.first>p2.first;
        else return p1.second>p2.second;
    }
};
class Solution {
public:
   
    map<int,priority_queue<pair<int,int>,vector<pair<int,int>>,com>> mp;
    void solve(TreeNode* root,int i,int j){
        if(root==NULL) return ;
        
        mp[i].push({root->val,j});
        solve(root->left,i-1,j+1);
        solve(root->right,i+1,j+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root,0,0);
        for(auto x:mp){
            vector<int> v;
            priority_queue<pair<int,int>,vector<pair<int,int>>,com> q = x.second;
            while(q.size()){
                v.push_back(q.top().first);
                q.pop();
            }
            ans.push_back(v);
        }
        return ans;
    }
};