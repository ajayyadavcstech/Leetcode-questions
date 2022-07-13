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
    struct triplet{
        TreeNode* node;
        TreeNode* parent;
        int x,y;
        triplet(TreeNode* root,int a,int b,TreeNode* parent){
            node = root;
            x = a;
            y = b;
            this->parent = parent;
        }
    };
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        //step 1 : Insert all heads into map
        unordered_map<int,TreeNode*> mp;
        for(auto x : trees){
            mp[x->val] = x;
        }
        //step 2 :  remove heads from map if its equivalent leaf node avaliable
        for(auto x : trees){
            if(x->left) mp.erase(x->left->val);
            if(x->right) mp.erase(x->right->val);
        }
        if(mp.size()!=1) return {};
        //step 3 : Again insert all heads into map except root 
        TreeNode* root = (*mp.begin()).second ;
        for(auto x : trees){
            mp[x->val] = x;
        }
        mp.erase(root->val);
        queue<triplet> q;
        if(root->left){ 
            triplet left(root->left,INT32_MIN,root->val,root);
            q.push(left);
        }
        if(root->right){
            triplet right(root->right,root->val,INT32_MAX,root);
            q.push(right);
        }
        while(q.size()>0){
            triplet front = q.front();
            q.pop();
            TreeNode* root = front.node;
            TreeNode* parent = front.parent;
            
            int x = front.x;
            int y = front.y;
            if(mp.find(root->val)!=mp.end()){
                TreeNode* child = mp[root->val];
                mp.erase(root->val);
                if(y==parent->val){
                    parent->left = child;
                }
                else{
                    parent->right = child;
                }
                if(child->left){ 
                    if(child->left->val<=x) return {};
                    triplet left(child->left,x,child->val,child);
                    q.push(left);
                }
                if(child->right){
                    if(child->right->val>=y) return {};
                    triplet right(child->right,child->val,y,child);
                    q.push(right);
                }
            }
        }
        if(mp.size()>0) return {};
        return root ;
    }
};