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
    deque<string> st;
    void solve(TreeNode* root){
        if(!root) return;
        
        string num = to_string(root->val);
        st.push_back(num);
            
        st.push_back("(");
        solve(root->left);
        st.push_back(")");
        
        st.push_back("(");
        solve(root->right);
        st.push_back(")");
        
        for(int i=0;i<2;i++){
            string first = st.back();st.pop_back();
            string second = st.back();st.pop_back();
            
            if(second=="(") continue;
            st.push_back(second);
            st.push_back(first);
        }
    }
    string tree2str(TreeNode* root) {
        string str;
        solve(root);
        while(st.size()){
            str.append(st.front());st.pop_front();
        }
        
        return str;
    }
};