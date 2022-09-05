/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        
        while(q.size()){
            int n = q.size();
            vector<int> v;
            while(n--){
                Node* node = q.front();
                v.push_back(node->val);
                q.pop();
                for(int i=0;i<node->children.size();i++){
                    q.push(node->children[i]);
                }
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};