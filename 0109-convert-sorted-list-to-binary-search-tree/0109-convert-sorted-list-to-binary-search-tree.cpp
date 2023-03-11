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
    TreeNode* build_BST(ListNode* left,ListNode* right){
        if(left==right) return NULL;
        
        
        ListNode* slow = left;
        ListNode* fast = left;
        while(fast!=right && fast->next!=right){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* node = new TreeNode(slow->val);
        node->left = build_BST(left,slow);
        node->right = build_BST(slow->next,right);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        return build_BST(head,NULL);
    }
};