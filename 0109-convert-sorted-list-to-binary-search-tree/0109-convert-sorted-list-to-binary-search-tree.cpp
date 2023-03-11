/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* build_BST(int s,int e,vector<int>&arr){
        if(s>e) return NULL;
        
        int mid = s + (e-s)/2;
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = build_BST(s,mid-1,arr);
        node->right = build_BST(mid+1,e,arr);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        vector<int> arr;
        ListNode* pt = head;
        while(pt){
            arr.push_back(pt->val);
            pt = pt->next;
        }
        return build_BST(0,arr.size()-1,arr);
    }
};